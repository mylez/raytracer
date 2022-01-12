
#include "glm/glm.hpp"

using namespace glm;

#include "Sphere.h"

/**
 *
 * @param ray
 * @param m
 * @param m_inv
 * @param inters_pos
 * @param norm
 * @return
 */
bool Sphere::do_intersect(Ray ray, mat4 m, vec3 &inters_pos, vec3 &norm) {

    // Convert the ray into the sphere's model coordinates, zero center
    // and unit radius.
    vec3 pos_ = vec3(inverse(m) * vec4(ray.pos, 1));
    vec3 dir_ = normalize(inverse(mat3(m)) * ray.dir);

    // Compute the portion of the quadratic formula that is inside the
    // square root. If it is negative then there is no intersection.
    float in_radical = pow(dot(dir_, pos_), 2) - dot(pos_, pos_) + 1;

    if (in_radical < 0)
        return false;

    // Solve the quadratic formula for the minimum non-negative solution.
    float t = -dot(dir_, pos_) - sqrt(in_radical);

    if (t < 0)
        t = -dot(dir_, pos_) + sqrt(in_radical);

    if (t < 0)
        return false;

    // Intersection position in model space.

    vec3 inters_pos_m = pos_ + t*dir_;

    inters_pos = vec3(m * vec4(inters_pos_m, 1));
    norm = normalize(transpose(inverse(mat3(m)))*inters_pos_m);

    return true;
}
