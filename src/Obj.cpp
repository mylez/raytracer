/*
Obj is subclass class of Geometry
that loads an obj file.
 This obj file loader only supports vertex positions and normals:
 v   x y z
 vn nx ny nz
 f 123//456
 i.e. there is no texture.
*/

#include <cstdio>
#include <iostream>
#include <vector>

#include "glm/glm.hpp"
using namespace glm;

#include "Obj.h"

#include "Ray.h"

#include "omp.h"

void Obj::init(const char * filename) {
    std::vector<vec3> temp_vertices;
    std::vector<vec3> temp_normals;
    std::vector<unsigned int> temp_vertexIndices;
    std::vector<unsigned int> temp_normalIndices;

    // load obj file
    FILE *file = fopen(filename , "r");

    if (!file) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        exit(-1);
    }

    std::cout << "Loading " << filename << "...";
    while (!feof(file)) {
        char lineHeader[128];

        memset(lineHeader, 0, sizeof(lineHeader));

        // read the first word of the line
        if (fscanf(file, "%s", lineHeader) == EOF)
            break; // EOF = End Of File. Quit the loop.

        // else : parse lineHeader
        if (strcmp(lineHeader, "v") == 0) {
            vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            temp_vertices.push_back(vertex);
        } else if (strcmp(lineHeader, "vn") == 0 ) {
            vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            temp_normals.push_back(normal);
        } else if (strcmp(lineHeader, "f") == 0 ) {
            //std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], normalIndex[3];
            fscanf(file, "%d//%d %d//%d %d//%d\n", &vertexIndex[0], &normalIndex[0], &vertexIndex[1],
                    &normalIndex[1], &vertexIndex[2], &normalIndex[2]);

            temp_vertexIndices.push_back(vertexIndex[0]);
            temp_vertexIndices.push_back(vertexIndex[1]);
            temp_vertexIndices.push_back(vertexIndex[2]);
            temp_normalIndices.push_back(normalIndex[0]);
            temp_normalIndices.push_back(normalIndex[1]);
            temp_normalIndices.push_back(normalIndex[2]);
        }
    }

    std::cout << "done" << std::endl;

    // post processing
    std::cout << "Processing data...";
    unsigned int n = temp_vertexIndices.size();
    vertices.resize(n);
    normals.resize(n);
    //indices.resize(n);

    for (unsigned int i = 0; i<n; i++) {
        //indices[i] = i;
        vertices[i] = temp_vertices[temp_vertexIndices[i] - 1];
        normals[i] = temp_normals[temp_normalIndices[i] - 1];
    }

    fclose(file);

    std::cout << "done (n = " << n << ")" << std::endl;
/*
    // setting up buffers
    std::cout << "Setting up buffers...";
    glGenVertexArrays(1, &vao );
    buffers.resize(3);
    glGenBuffers(3, buffers.data());
    glBindVertexArray(vao);

    // 0th attribute: position
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, n*sizeof(vec3), &vertices[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

    // 1st attribute: normal
    glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
    glBufferData(GL_ARRAY_BUFFER, n*sizeof(vec3), &normals[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);

    // indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, n*sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);

    count = n;
    glBindVertexArray(0);
    std::cout << "done." << std::endl;
*/
}

/**
 *
 * @param ray
 * @param m
 * @param pos
 * @param norm
 * @return
 */
bool Obj::do_intersect(Ray ray, mat4 m, vec3 &pos, vec3 &norm) {

    float t = std::numeric_limits<float>::max();
    mat3 a_inv_t = inverse(transpose(mat3(m)));
    bool found = false;

    for (int i = 0; i < vertices.size() - 2; i += 3) {

        vec4 v_a = m*vec4(vertices[i], 1);
        vec4 v_b = m*vec4(vertices[i+1], 1);
        vec4 v_c = m*vec4(vertices[i+2], 1);

        vec3 n_a = a_inv_t * normals[i];
        vec3 n_b = a_inv_t * normals[i+1];
        vec3 n_c = a_inv_t * normals[i+2];

        mat4 Pd(v_a, v_b, v_c, -vec4(ray.dir, 0));

        vec4 L = inverse(Pd) * vec4(ray.pos, 1);

        if (L.x >= 0 && L.y >= 0 && L.z >= 0 && L.w >= 0 && L.w < t) {
            t = L.w;
            pos = vec3(v_a*L.x + v_b*L.y + v_c*L.z);
            norm = normalize(n_a*L.x + n_b*L.y + n_c*L.z);
            found = true;
        }
    }

    return found;
}

