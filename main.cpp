#include <iostream>
using namespace std;
#define GLM_FORCE_RADIANS

#include "Scene.h"

int main(int argc, char *argv[]) {

   Scene scene;

   scene.init();
   scene.draw();
}
