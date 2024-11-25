include "MeshGenerator.h"

Mesh MeshGenerator::generate3DMesh(const Mesh& mesh2D, float height) {
Mesh mesh3D = mesh2D;
int numVertices = mesh2D.vertices.size();

// add top vertices
for (const auto &vertex : mesh2D.vertices) {
    mesh3D.addVertex(vertex.x, vertex.y, height);
}

// add side faces
for (const auto& face : mesh2D.faces) {
        mesh3D.addFace(face.v1, face.v2, face.v3);
        mesh3D.addFace(face.v1 + numVertices, face.v2 + numVertices, face.v3 + numVertices);
}

return mesh3D;
}