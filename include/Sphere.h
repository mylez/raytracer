#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "Geometry.h"
#include "glm/glm.hpp"

using namespace glm;

#include <iostream>

struct Sphere: public Geometry {

    Sphere() {
        std::cout << "sphere created\n";
    }

    bool do_intersect(Ray, mat4, vec3 &, vec3 &) override;
};

#endif
