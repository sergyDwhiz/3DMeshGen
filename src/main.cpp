#include "FileHandler.h"
#include "MeshGenerator.h"
#include <iostream>

int main() {
    std::string inputFile = "data/input_mesh.txt";
    std::string outputFile = "data/output_mesh.obj";
    float height = 1.0f;

    Mesh mesh2D = FileHandler::read2DMesh(inputFile);
    if (mesh2D.vertices.empty()) {
        std::cerr << "Failed to load 2D mesh from " << inputFile << std::endl;
        return 1;
    }

    Mesh mesh3D = MeshGenerator::generate3DMesh(mesh2D, height);
    FileHandler::write3DMesh(outputFile, mesh3D);

    std::cout << "3D mesh generated and saved to " << outputFile << std::endl;
    return 0;
}
