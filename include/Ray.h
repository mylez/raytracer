#ifndef __RAYTRACE_H__
#define __RAYTRACE_H__

#include <iostream>

#include "glm/glm.hpp"

struct Ray {
    glm::vec3 pos;
    glm::vec3 dir;
};

#endif