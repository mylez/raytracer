#ifndef __OBJ_H__
#define __OBJ_H__

/*
Obj is subclass class of Geometry
that loads an obj file.
*/

#include <vector>
#include <glm/glm.hpp>
#include "Geometry.h"

struct Obj: public Geometry {

    std::vector<glm::vec3> vertices, normals;

    void init(const char * filename) override;

    // todo - implement Geometry::intersection for obj. Looping over each triangle,
    //        return the world-space position of the intersection and the
    //        interpolated normal for the position. Use barycentric coordinates.

    bool do_intersect(Ray, glm::mat4, glm::vec3 &, glm::vec3 &) override;
};

#endif
