// Read and write mesh files
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Mesh.h"
#include <string>

class FileHandler {
public:
    static Mesh read2DMesh(const std::string& filename);
    static void write3DMesh(const std::string& filename, const Mesh& mesh);
};

#endif