#include <iostream>
using namespace std;

#define GLM_FORCE_RADIANS

#include "Scene.h"


int main(int argc, char *argv[]) {

   printf("This is the ray tracer.\n");

   Scene scene;

   scene.init();

   scene.draw();

}
