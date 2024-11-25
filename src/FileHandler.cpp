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