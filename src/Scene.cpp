/**************************************************
Scene.cpp contains the implementation of the draw command
*****************************************************/

#include <iostream>
#include <FreeImage.h>

#include "Scene.h"
#include "Cube.h"

// The scene init definition
#include "Scene.inl"

#include "omp.h"

static const float NORM_SHIFT_DELTA = 0.01;

/**
 * Refer to page 21 of the ray tracing lecture slides.
 *
 * Returns a world-space ray through the given pixel.
 * The ray has unit direction.
 *
 * Should be called _after_ compute_matrices.
 *
 * @param i column position of pixel
 * @param j row position of pixel
 * @param randomize If false, each ray goes through the center of the pixel (i.e. 0.5,0.5).
 * Otherwise a random sample is chosen through each pixel.
 *
 * @return A ray in world space originating from the camera, passing through
 * pixel (i, j), with normalized dir.
 *
 * @author Miles
 */
Ray Scene::ray_into_pixel(int i, int j, bool randomize) {

    // Non-randomized initial values
    float offset_a = 0.5;
    float offset_b = 0.5;

    // Choose random offsets within [0, 1] if randomize is set.
    if (randomize) {
        offset_a = rand() / float(RAND_MAX);
        offset_b = rand() / float(RAND_MAX);
    }

    // Compute the alpha and beta values as per slide 21.
    float alpha = 2 * (offset_a + (float) i) / ((float) camera->width_px) - 1;
    float beta = 1 - 2 * (offset_b + (float) j) / (float) camera->height_px;
    const float tan_fovy = tan((camera->fovy/2)*(M_PI/180));

    // Scale by the virtual image width and height, taking into account fov.
    alpha *= tan_fovy*camera->aspect;
    beta *= tan_fovy;

    glm::vec3 u = glm::vec3(camera->cam[0]);
    glm::vec3 v = glm::vec3(camera->cam[1]);
    glm::vec3 w = glm::vec3(camera->cam[2]);

    return {glm::vec3(camera->cam[3]), glm::normalize(alpha*u + beta*v - w)};
}

/**
 * Given a ray through the scene, find the closest geometry intersection via dfs.
 *
 * Outputs relevant material, position, normal vector, and distance through
 * reference output parameters.
 *
 * Should be called after compute_matrices is called.
 *
 * @param ray The ray (with position and direction) with which to find the closest intersecting object.
 *
 * @return true if intersection found otherwise false
 *
 * @author Miles (based on the dfs draw function from hw3).
 */
Intersect Scene::intersection(Ray ray) {
    std::stack<Node *> dfs_stack;
    std::stack<glm::mat4> mat_stack;

    // Return value.
    Intersect intersect;

    // Identity matrix is used instead of Camera.view to keep the vertices
    // in world coordinates rather than camera coordinates for ray tracing.
    mat_stack.push(mat4(1));
    dfs_stack.push(node["world"]);

    while (!dfs_stack.empty()) {

        // Pop the current node/matrix from the DFS stack.
        const Node *cur_node = dfs_stack.top();
        const glm::mat4 cur_m = mat_stack.top();
        dfs_stack.pop();
        mat_stack.pop();

        // Test model geometries for intersection with this ray.
        for (int i = 0; i < cur_node->models.size(); i++) {

            Geometry *cur_geo = cur_node->models[i]->geometry;

            // Complete the model matrix and its inverse-transpose.
            glm::mat4 m = cur_m*cur_node->model_transforms[i];

            // If an intersection is found for this geometry object, the inters_pos and normal
            // variables will be updated here (they are passed by reference).
            //
            // note - intersection needs the model matrix to bring the model vertices into world
            //        coordinates, matching the ray's coordinate frame. Its inverse-transpose
            //        is needed to transform normal vectors, and maybe other stuff too.

            vec3 inters_pos_, norm_;

            if (cur_geo->do_intersect(ray, m, inters_pos_, norm_)) {

                float dist_ = glm::distance(camera->eye, inters_pos_);

                // Update the rest of the output parameters if this intersection is
                // closer to the camera.
                if (dist_ < intersect.distance) {
                    intersect.material = cur_node->models[i]->material;
                    intersect.distance = dist_;
                    intersect.position = inters_pos_;
                    intersect.normal = norm_;

                    intersect.found = true;
                }
            }
        }

        // Prepare the children of the current node to be visited by DFS.
        //
        // Todo - a bounding-box check could go here to prune the search tree.
        //
        for (int i = 0; i < cur_node->child_nodes.size(); i++) {
            dfs_stack.push(cur_node->child_nodes[i]);
            mat_stack.push(cur_m * cur_node->child_transforms[i]);
        }
    }

    return intersect;
}

static void print_ray(Ray r) {
    printf("<%.3f, %.3f, %.3f><%.3f, %.3f, %.3f>\n", r.pos.x, r.pos.y, r.pos.z, r.dir.x, r.dir.y, r.dir.z);
}

static void print_vec(vec3 v) {
    printf("<%.3f, %.3f, %.3f>, |V| = %.4f\n", v.x, v.y, v.z, length(v));
}


/**
 *
 * @param incoming_ray
 * @param intersect
 * @param rec_depth
 * @return
 */
vec4 Scene::colorizer(Ray incoming_ray, Intersect intersect, unsigned int rec_depth) {

    // If recursion depth has been reached, simply return black.
    if (rec_depth == 0) {
        return vec4(0);
    }

    const vec3 in_dir = incoming_ray.dir;
    const vec3 normal = intersect.normal;

    const Material &material = *intersect.material;

    // All objects are shaded with ambient light independent of light source.
    vec4 color = material.ambient;

    // Loop over each light source to compute diffuse lighting.
    for (auto &el: light_store) {
        Light *light = el.second;
        vec3 light_dir = -normalize(intersect.position - vec3(light->position));

        // Calculate visibility for this light source.
        Ray sec_ray {
            intersect.position + intersect.normal * NORM_SHIFT_DELTA,
            light_dir};

        Intersect sec_inters = intersection(sec_ray);

        // Surface visible from light source gets Lambertian and Phong shading
        if (!sec_inters.found) {

            // Lambertian.
            color += material.diffuse*light->color * max(dot(intersect.normal, light_dir), 0.f);

            // Phong lighting model.
            vec3 refl_light = 2.f * dot(intersect.normal, light_dir)*intersect.normal - light_dir;
            color += material.specular * light->color
                     * pow(max(dot(-incoming_ray.dir, refl_light), 0.f), material.shininess);
        }
    }

    // This is the recursive speculative lighting.
    if (vec3(material.specular) != vec3(0)) {
        // Compute the reflected ray based on the reflection formula r = 2(n*in) - in.
        Ray refl_ray {
                intersect.position + intersect.normal * NORM_SHIFT_DELTA,
                -normalize(2*dot(normal, in_dir)*normal - in_dir)};

        Intersect refl_inters = intersection(refl_ray);

        // If there is a reflectingi object, add its color with a recursive call.
        if (refl_inters.found) {
            color += material.specular*colorizer(refl_ray, refl_inters, rec_depth - 1);
        }
    }

    return color;
}



/*
 *  Old draw function from hw3 with opengl code removed.
 *
 *  todo - update this function to iterate over and cast rays through
 *         each pixel in the image as per the ray tracing algorithm.
 */
void Scene::draw() {

    const int width = camera->width_px;
    const int height = camera->height_px;

    // Update the camera matrix.
    camera->compute_matrices();
    //std::vector<color_24bpp> pixels;

    color_24bpp *pixels = new color_24bpp[width * height * 3];

    int pixels_colored = 0;

#pragma omp parallel for
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {

            vec4 color = vec4(0);

            for (int s = 0; s < num_samples; s++) {

                // Produce a ray through pixel i,j. Randomize it if num_samples > 1.
                Ray ray = ray_into_pixel(i, j, num_samples > 1);
                Intersect intersect = intersection(ray);

                if (intersect.found) {
                    color += colorizer(ray, intersect, 10);
                }
            }

            color /= float(num_samples);

            pixels[i + j*width] = color_24bpp::from_float(color);
        }

        pixels_colored += width;
        if (j%100==0) printf("%.3f percent\n", (100.f*pixels_colored/(float)(height*width)));
    }

    FIBITMAP *img = FreeImage_ConvertFromRawBits((BYTE *) pixels, width, height, width*3, 24, 0, 0, 0, true);
    std::cout << "Saving screenshot: " << "test.png" << std::endl;
    FreeImage_Save(FIF_PNG, img, "test.png", 0);

    delete[] pixels;
}
