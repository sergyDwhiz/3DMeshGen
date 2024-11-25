cmake_minimum_required(VERSION 3.10)
project(MeshGen)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(MeshGen
    src/main.cpp
    src/Mesh.cpp
    src/FileHandler.cpp
    src/MeshGenerator.cpp
)