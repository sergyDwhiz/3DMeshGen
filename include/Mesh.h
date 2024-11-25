// Defines a Mesh class that represents a 3D mesh with vertices and faces.

#ifndef MESH_H
#define MESH_H

#include <vector>

struct Vertex {
    float x, y, z;
};

struct Face {
    int v1, v2, v3;
};

class Mesh {
public:
    std::vector<Vertex> vertices;
    std::vector<Face> faces;

    void addVertex(float x, float y, float z);
    void addFace(int v1, int v2, int v3);
};

#endif