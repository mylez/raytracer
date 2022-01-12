/**************************************************
Scene.inl contains the definition of the scene graph
*****************************************************/
#include "Scene.h"
#include "Sphere.h"
#include "Obj.h"

using namespace glm;

static int num_samples = 10;

void Scene::init() {
    // Create a geometry_store palette

    geometry_store["sphere"] = new Sphere;

    geometry_store["teapot"] = new Obj;
    geometry_store["teapot"]->init("models/teapot.obj");
    geometry_store["bunny"] = new Obj;
    geometry_store["bunny"]->init("models/teapot.obj");

    float _spec = 0.3;

    // Create a material_store palette
    material_store["blue"] = new Material;
    material_store["blue"]->ambient = vec4(.05, .2, .52, 1)*vec4(vec3(0.1),1);
    material_store["blue"]->diffuse = vec4(.05, .2, .52, 1);
    material_store["blue"]->specular = vec4(vec3(.25), 1);
    material_store["blue"]->shininess = 100.0f;

    // Create a material_store palette
    material_store["purple"] = new Material;
    material_store["purple"]->ambient = vec4(.85, .1, .78, 1)*vec4(vec3(0.05),1);
    material_store["purple"]->diffuse = vec4(0.58039, 0.0, 0.82745, 1);
    material_store["purple"]->specular = vec4(0);
    material_store["purple"]->shininess = 100.0f;

    // Create a material_store palette
    material_store["white"] = new Material;
    material_store["white"]->ambient = vec4(1,1,1, 1)*vec4(vec3(0.05),1);
    material_store["white"]->diffuse = vec4(.9,.9,.9, 1);
    material_store["white"]->specular = vec4(vec3(0), 1.0f);
    material_store["white"]->shininess = 100.0f;

    // Create a material_store palette
    material_store["red"] = new Material;
    material_store["red"]->ambient = vec4(.5, .122, .143, 1)*vec4(vec3(0.05),1);
    material_store["red"]->diffuse = vec4(.5, .122, .143, 1);
    material_store["red"]->specular = vec4(vec3(_spec), 1.0f);
    material_store["red"]->shininess = 100.0f;

    // Create a material_store palette
    material_store["red_matte"] = new Material;
    material_store["red_matte"]->ambient = vec4(.5, .122, .143, 1)*vec4(vec3(0.05),1);
    material_store["red_matte"]->diffuse = vec4(.5, .122, .143, 1);
    material_store["red_matte"]->specular = vec4(vec3(0), 1.0f);
    material_store["red_matte"]->shininess = 100.0f;

    // Create a material_store palette
    material_store["blue_matte"] = new Material;
    material_store["blue_matte"]->ambient = vec4(.1, .1, .7, 1)*vec4(vec3(0.05),1);
    material_store["blue_matte"]->diffuse = vec4(.1, .1, .7, 1);
    material_store["blue_matte"]->specular = vec4(vec3(0), 1.0f);
    material_store["blue_matte"]->shininess = 100.0f;
    // Create a material_store palette
    material_store["white_shiny"] = new Material;
    material_store["white_shiny"]->ambient = vec4(.9,.9,.9, 1)*vec4(vec3(0.05),1);
    material_store["white_shiny"]->diffuse = vec4(.9,.9,.9, 1);
    material_store["white_shiny"]->specular = vec4(vec3(.31), 1.0f);
    material_store["white_shiny"]->shininess = 100.0f;

    // Create a material_store palette
    material_store["shiny_white"] = new Material;
    material_store["shiny_white"]->ambient = vec4(1,1,1, 1)*vec4(vec3(0.05),1);
    material_store["shiny_white"]->diffuse = vec4(1,1,1,1);
    material_store["shiny_white"]->specular = vec4(vec3(1,0,0), 1.0f);
    material_store["shiny_white"]->shininess = 100.0f;
    // Create a material_store palette
    material_store["shiny_red"] = new Material;
    material_store["shiny_red"]->ambient = vec4(.8,.1,.145, 1)*vec4(vec3(0.05),1);
    material_store["shiny_red"]->diffuse = vec4(.8,.1,.145,1);
    material_store["shiny_red"]->specular = vec4(vec3(.333), 1.0f);
    material_store["shiny_red"]->shininess = 30.0f;

    // Create a material_store palette
    material_store["grey"] = new Material;
    material_store["grey"]->diffuse = vec4(.5,.5,.5, 1.0f);
    material_store["grey"]->ambient = material_store["grey"]->diffuse*vec4(vec3(.07), 1);
    material_store["grey"]->specular = vec4(vec3(.5), 1.0f);
    material_store["grey"]->shininess = 100.0f;

    // Create a material_store palette
    material_store["green"] = new Material;
    material_store["green"]->diffuse = vec4(.01,.5,.03, 1.0f);
    material_store["green"]->ambient = material_store["grey"]->diffuse*vec4(vec3(.07), 1);
    material_store["green"]->specular = vec4(vec3(_spec), 1.0f);
    material_store["green"]->shininess = 100.0f;

    // Create a model_store palette
    model_store["blue_sphere"] = new Model;
    model_store["blue_sphere"]->geometry = geometry_store["sphere"];
    model_store["blue_sphere"]->material = material_store["blue"];

    // Create a model_store palette
    model_store["red_sphere"] = new Model;
    model_store["red_sphere"]->geometry = geometry_store["sphere"];
    model_store["red_sphere"]->material = material_store["red"];

    // Create a model_store palette
    model_store["red_matte_sphere"] = new Model;
    model_store["red_matte_sphere"]->geometry = geometry_store["sphere"];
    model_store["red_matte_sphere"]->material = material_store["red_matte"];

    // Create a model_store palette
    model_store["blue_matte_sphere"] = new Model;
    model_store["blue_matte_sphere"]->geometry = geometry_store["sphere"];
    model_store["blue_matte_sphere"]->material = material_store["blue_matte"];

    // Create a model_store palette
    model_store["grey_sphere"] = new Model;
    model_store["grey_sphere"]->geometry = geometry_store["sphere"];
    model_store["grey_sphere"]->material = material_store["grey"];
    // Create a model_store palette
    model_store["white_sphere"] = new Model;
    model_store["white_sphere"]->geometry = geometry_store["sphere"];
    model_store["white_sphere"]->material = material_store["white"];
    // Create a model_store palette
    model_store["grey_sphere"] = new Model;
    model_store["grey_sphere"]->geometry = geometry_store["sphere"];
    model_store["grey_sphere"]->material = material_store["grey"];
    // Create a model_store palette
    model_store["purple_sphere"] = new Model;
    model_store["purple_sphere"]->geometry = geometry_store["sphere"];
    model_store["purple_sphere"]->material = material_store["purple"];
    // Create a model_store palette
    model_store["shiny_white_sphere"] = new Model;
    model_store["shiny_white_sphere"]->geometry = geometry_store["sphere"];
    model_store["shiny_white_sphere"]->material = material_store["shiny_white"];


    // Create a model_store palette
    model_store["green_sphere"] = new Model;
    model_store["green_sphere"]->geometry = geometry_store["sphere"];
    model_store["green_sphere"]->material = material_store["green"];


    // Create a model_store palette
    model_store["grey_teapot"] = new Model;
    model_store["grey_teapot"]->geometry = geometry_store["teapot"];
    model_store["grey_teapot"]->material = material_store["grey"];

    // Create a model_store palette
    model_store["blue_teapot"] = new Model;
    model_store["blue_teapot"]->geometry = geometry_store["teapot"];
    model_store["blue_teapot"]->material = material_store["blue_matte"];

    // Create a model_store palette
    model_store["red_matte_teapot"] = new Model;
    model_store["red_matte_teapot"]->geometry = geometry_store["teapot"];
    model_store["red_matte_teapot"]->material = material_store["red_matte"];
    // Create a model_store palette
    model_store["shiny_red_teapot"] = new Model;
    model_store["shiny_red_teapot"]->geometry = geometry_store["teapot"];
    model_store["shiny_red_teapot"]->material = material_store["shiny_red"];

    // Create a model_store palette
    model_store["blue_bunny"] = new Model;
    model_store["blue_bunny"]->geometry = geometry_store["bunny"];
    model_store["blue_bunny"]->material = material_store["blue_matte"];
    // Create a model_store palette
    model_store["white_bunny"] = new Model;
    model_store["white_bunny"]->geometry = geometry_store["bunny"];
    model_store["white_bunny"]->material = material_store["white_shiny"];

    // Create a model_store palette
    model_store["green_bunny"] = new Model;
    model_store["green_bunny"]->geometry = geometry_store["bunny"];
    model_store["green_bunny"]->material = material_store["green"];
    // Create a model_store palette
    model_store["red_teapot"] = new Model;
    model_store["red_teapot"]->geometry = geometry_store["teapot"];
    model_store["red_teapot"]->material = material_store["red_matte"];


/*
    // Add lights
    light_store["green_bulb"] = new Light;
    light_store["green_bulb"]->position = vec4(-3, 0, 20, 0);
    light_store["green_bulb"]->color = vec4(.1, 1, .2,1);

    // Add lights
    light_store["red_bulb"] = new Light;
    light_store["red_bulb"]->position = vec4(3, 0, 20, 0);
    light_store["red_bulb"]->color = vec4(1,.12,.14,1);

    // Add lights
    light_store["blue_bulb"] = new Light;
    light_store["blue_bulb"]->position = vec4(0, 0, 20, 0);
    light_store["blue_bulb"]->color = vec4(0,.12,1,1);
*/
    // Add lights
    //light_store["top_bulb"] = new Light;
    //light_store["top_bulb"]->position = vec4(0, 4, 4, 0);
    //light_store["top_bulb"]->color = vec4(.5,.5,.5,1);

    // Add lights
    light_store["white_bulb"] = new Light;
    light_store["white_bulb"]->position = vec4(0, 10, 0, 0);
    light_store["white_bulb"]->color = vec4(vec3(1,.97,.9),1);


    light_store["bulb_2"] = new Light;
    light_store["bulb_2"]->position = vec4(0, -10, -4, 0);
    light_store["bulb_2"]->color = vec4(.9, .2, .1,1);

    // Build the scene graph






    node["world"]->models.push_back(model_store["green_sphere"]);
    node["world"]->model_transforms.push_back(translate(vec3(1, 2, -.4))*scale(vec3(.2)));


    node["world"]->models.push_back(model_store["grey_sphere"]);
    node["world"]->model_transforms.push_back(translate(vec3(0, 2, 2))*rotate(float(-M_PI/12), vec3(1, 1, 0))*scale(vec3(1,1,.4)));


    node["world"]->models.push_back(model_store["red_sphere"]);
    node["world"]->model_transforms.push_back(translate(vec3(0, 0, .87))*scale(vec3(1.2)));

    node["world"]->models.push_back(model_store["blue_matte_sphere"]);
    node["world"]->model_transforms.push_back(translate(vec3(-.2, 1.7, -.4))*scale(vec3(.2)));

    node["world"]->models.push_back(model_store["purple_sphere"]);
    node["world"]->model_transforms.push_back(translate(vec3(-.3, 2.2, -.7))*scale(vec3(.1)));




    // Put a camera
    camera = new Camera;
    camera->height_px = 2048;
    camera->width_px = 2048;
    camera->aspect_default = 1;
    camera->eye_default = vec3(0, 5, -7);
    camera->up_default = vec3(0, 1, 0);
    camera->target_default = vec3(0, 2, 0);
    camera->fovy_default=25;
    camera->reset();

    // Initialize shader
    //shader = new SurfaceShader;
    //shader -> read_source( "shaders/projective.vert", "shaders/lighting.frag" );
    //shader -> compile();
    //glUseProgram(shader -> program);
    //shader -> initUniforms();
}
