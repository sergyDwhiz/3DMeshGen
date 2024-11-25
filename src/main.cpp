#include "FileHandler.h"
#include "MeshGenerator.h"
#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string inputFile;
    char choice;

    std::cout << "Do you want to load your own 2D mesh file? (y/n): ";
    std::cin >> choice;
    std::cin.ignore(); // Ignore the newline character left in the buffer

    if (choice == 'y' || choice == 'Y') {
        std::cout << "Enter the path to the 2D mesh file: ";
        std::getline(std::cin, inputFile);
    } else {
        inputFile = "../data/input_mesh.txt"; // Default file path
    }

    // Debugging output to verify the file path
    std::cout << "Attempting to open file: " << inputFile << std::endl;

    // Check if the file can be opened
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << inputFile << std::endl;
        return 1;
    }
    file.close();

    Mesh mesh2D;
    if (inputFile.substr(inputFile.find_last_of(".") + 1) == "stl") {
        mesh2D = FileHandler::read2DMeshFromSTL(inputFile);
    } else {
        mesh2D = FileHandler::read2DMesh(inputFile);
    }

    if (mesh2D.vertices.empty()) {
        std::cerr << "Failed to load 2D mesh from " << inputFile << std::endl;
        return 1;
    }

    std::string outputFile = "../data/output_mesh.obj";
    float height = 1.0f;

    Mesh mesh3D = MeshGenerator::generate3DMesh(mesh2D, height);
    FileHandler::write3DMesh(outputFile, mesh3D);

    std::cout << "3D mesh generated and saved to " << outputFile << std::endl;
    return 0;
}