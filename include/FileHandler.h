#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Mesh.h"
#include <string>

class FileHandler {
public:
    static Mesh read2DMesh(const std::string& filename);
    static Mesh read2DMeshFromSTL(const std::string& filename); // Ensure this declaration exists
    static void write3DMesh(const std::string& filename, const Mesh& mesh);
};

#endif // FILEHANDLER_H