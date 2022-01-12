/**************************************************
Camera is a class for a camera object.
*****************************************************/
#ifndef __CAMERA_H__
#define __CAMERA_H__

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "Ray.h"

struct Camera {

    int width_px = 256, height_px = 256;

    glm::vec3 *colors;

    // todo - add some kind of "film" element here for storing image pixels (a 2- or 3-D array of pixel colors).

    glm::vec3 eye;// position of the eye
    glm::vec3 target;  // look at target
    glm::vec3 up;      // up vector

    float fovy;  // field of view in degrees
    float aspect; // aspect ratio
    float near; // near clipping distance
    float far; // far clipping distance
    
    // default values for reset
    glm::vec3 eye_default = glm::vec3(5.0f, 0.0f, 0.0f);
    glm::vec3 target_default = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 up_default = glm::vec3(0.0f, 1.0f, 0.0f);
    float fovy_default = 30.0f;
    float aspect_default = 1.0f;//4.0f/3.0f;
    float near_default = 0.01f;
    float far_default = 100.0f;

    glm::mat4 cam = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);   // view matrix
    glm::mat4 proj = glm::mat4(1.0f);   // projection matrix
    
    void rotateRight(float degrees);
    void rotateUp(float degrees);
    void zoom(float factor);
    void compute_matrices();
    void reset();
};

#endif 
