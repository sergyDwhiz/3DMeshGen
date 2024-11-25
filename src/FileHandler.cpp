#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

Mesh FileHandler::read2DMesh(const std::string& filename) {
    Mesh mesh;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return mesh;
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char type;
        iss >> type;
        if (type == 'v') {
            float x, y;
            iss >> x >> y;
            mesh.addVertex(x, y, 0.0f);
        } else if (type == 'f') {
            int v1, v2, v3;
            iss >> v1 >> v2 >> v3;
            mesh.addFace(v1, v2, v3);
        }
    }

    return mesh;
}

Mesh FileHandler::read2DMeshFromSTL(const std::string& filename) {
    Mesh mesh;
    std::ifstream file(filename, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return mesh;
    }

    // Skip the header
    file.seekg(80);

    uint32_t numTriangles;
    file.read(reinterpret_cast<char*>(&numTriangles), sizeof(numTriangles));

    for (uint32_t i = 0; i < numTriangles; ++i) {
        float normal[3];
        float vertex1[3], vertex2[3], vertex3[3];
        uint16_t attributeByteCount;

        file.read(reinterpret_cast<char*>(normal), sizeof(normal));
        file.read(reinterpret_cast<char*>(vertex1), sizeof(vertex1));
        file.read(reinterpret_cast<char*>(vertex2), sizeof(vertex2));
        file.read(reinterpret_cast<char*>(vertex3), sizeof(vertex3));
        file.read(reinterpret_cast<char*>(&attributeByteCount), sizeof(attributeByteCount));

        // Add vertices to the mesh (only x and y coordinates)
        mesh.addVertex(vertex1[0], vertex1[1], 0.0f);
        mesh.addVertex(vertex2[0], vertex2[1], 0.0f);
        mesh.addVertex(vertex3[0], vertex3[1], 0.0f);

        // Add face to the mesh
        int v1 = mesh.vertices.size() - 3 + 1;
        int v2 = mesh.vertices.size() - 2 + 1;
        int v3 = mesh.vertices.size() - 1 + 1;
        mesh.addFace(v1, v2, v3);
    }

    return mesh;
}

void FileHandler::write3DMesh(const std::string& filename, const Mesh& mesh) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& vertex : mesh.vertices) {
        file << "v " << vertex.x << " " << vertex.y << " " << vertex.z << "\n";
    }

    for (const auto& face : mesh.faces) {
        file << "f " << face.v1 << " " << face.v2 << " " << face.v3 << "\n";
    }
}