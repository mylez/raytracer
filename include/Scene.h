#ifndef __SCENE_H__
#define __SCENE_H__
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
using namespace glm;

#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_normalized_axis.hpp>

#include <vector>
#include <string>
#include <map>
#include <stack>

#include "Camera.h"
#include "Light.h"
#include "Geometry.h"
#include "Material.h"
#include "Model.h"
#include "Ray.h"

struct Node {
    std::vector<Node *> child_nodes;
    std::vector<glm::mat4> child_transforms;
    std::vector<Model *> models;
    std::vector<glm::mat4> model_transforms;
};

struct Intersect {
    Material *material = nullptr;
    vec3 position = vec3(0);
    vec3 normal = vec3(0);
    float distance = INFINITY;
    bool found = false;
};

struct Scene {
    Camera *camera;
    //SurfaceShader *shader;

    // The following are containers of objects serving as the object palettes.
    // The containers store pointers so that they can also store derived class objects.
    std::map<std::string, Geometry *> geometry_store;
    std::map<std::string, Material *> material_store;
    std::map<std::string, Model *> model_store;
    std::map<std::string, Light *> light_store;
    
    // The container of nodes will be the scene graph after we connect the nodes by setting the child_nodes.
    std::map<std::string, Node*> node;
 
    Scene() {
        // the default scene graph already has one node named "world."
        node["world"] = new Node;
    }

    void init();

    Ray ray_into_pixel(int, int, bool);

    Intersect intersection(Ray ray);

    vec4 colorizer(Ray incoming_ray, Intersect intersect, unsigned int rec_depth);

    void draw();

    // destructor
    ~Scene() {
        // The containers of pointers own the object pointed to by the pointers.
        // All the objects should be deleted when the object palette is destructed.
        // light_store
        for (auto e: light_store)
            delete e.second;
        // geometry_store
        for (auto e: geometry_store)
            delete e.second;
        // material_store
        for (auto e: material_store)
            delete e.second;
        // model_store
        for (auto e: model_store)
            delete e.second;
        // model_store
        for (auto e: node)
            delete e.second;

        delete camera;
        //delete shader;
    }
};


struct color_24bpp {
    uint8_t b;
    uint8_t g;
    uint8_t r;

    color_24bpp() {
        r = g = b = 0;
    };

    static color_24bpp from_float(vec4 c) {
        return from_float(vec3(c));
    }

    static color_24bpp from_float(vec3 c) {
        color_24bpp c24;

        c24.r = 255 * c.x;
        c24.g = 255 * c.y;
        c24.b = 255 * c.z;

        // Not sure why glm::min / glm::max aren't working here but I'm moving on.
        if (255 * c.x < 0) c24.r = 0;
        if (255 * c.x > 255) c24.r = 255;
        if (255 * c.y < 0) c24.g = 0;
        if (255 * c.y > 255) c24.g = 255;
        if (255 * c.z < 0) c24.b = 0;
        if (255 * c.z > 255) c24.b = 255;

        return c24;
    }

};

#endif 
