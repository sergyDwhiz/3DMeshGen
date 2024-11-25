# 3D Mesh Generator

## Overview

The 3D Mesh Generator is a C++ project that converts 2D meshes or other models into 3D meshes. This tool reads 2D mesh data, extrudes it along the z-axis, and exports the resulting 3D mesh in a standard file format like OBJ.

## Features

- **2D to 3D Conversion**: Easily convert 2D mesh data into 3D meshes.
- **Customizable Height**: Specify the height for the extrusion to create the 3D mesh.
- **OBJ Export**: Export the generated 3D mesh to an OBJ file for use in various 3D applications.

## File Structure

## Getting Started

### Prerequisites

- C++11 or later
- CMake 3.10 or later

### Building the Project

1. Clone the repository:
    ```sh
    git clone <https://github.com/sergyDwhiz/MeshGen>
    cd MeshGen
    ```

2. Create a build directory and navigate into it:
    ```sh
    mkdir build
    cd build
    ```

3. Run CMake to configure the project:
    ```sh
    cmake ..
    ```

4. Build the project:
    ```sh
    make
    ```

### Running the Project

1. Prepare your 2D mesh data in [`data/input_mesh.txt`](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fhome%2Fsergy%2FMeshGen%2Fdata%2Finput_mesh.txt%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/home/sergy/MeshGen/data/input_mesh.txt") in the following format:
    ```
    v x1 y1
    v x2 y2
    ...
    f v1 v2 v3
    ...
    ```

2. Run the executable:
    ```sh
    ./3DMeshGenerator
    ```

3. The generated 3D mesh will be saved to `data/output_mesh.obj`.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request.

## License

This project is licensed under the MIT License - see the [`LICENSE`](command:_github.copilot.openRelativePath?%5B%7B%22scheme%22%3A%22file%22%2C%22authority%22%3A%22%22%2C%22path%22%3A%22%2Fhome%2Fsergy%2FMeshGen%2FLICENSE%22%2C%22query%22%3A%22%22%2C%22fragment%22%3A%22%22%7D%5D "/home/sergy/MeshGen/LICENSE") file for details.

## Acknowledgements

- Inspired by various 3D modeling tools and libraries.
- Special thanks to the open-source community for their invaluable resources and support.