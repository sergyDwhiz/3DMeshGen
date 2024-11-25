// defines the functions to add vertices and faces to a mesh.

#include "Mesh.h"

void Mesh::addVertex(float x, float y, float z) {
    vertices.push_back({x, y, z});
}

void Mesh::addFace(int v1, int v2, int v3) {
    faces.push_back({v1, v2, v3});
}