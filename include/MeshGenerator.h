// Generate 3D mesh from 2D mesh

#ifndef MESHGENERATOR_H
#define MESHGENERATOR_H

#include "Mesh.h"

class MeshGenerator {
public:
    static Mesh generate3DMesh(const Mesh& mesh2D, float height);
};

#endif