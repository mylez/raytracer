/**************************************************
A model_store is a geometry_store with material_store.
*****************************************************/
#include "Geometry.h"
#include "Material.h"

#ifndef __MODEL_H__
#define __MODEL_H__

struct Model {
    Geometry* geometry;
    Material* material;
};

#endif 
