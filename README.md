# WIP: a project for demonstrating better collision detection pratctices for Minecraft physics

- An easier to read and better interface for grid marching (gridmarch.h and gridmarch.cpp; full visualiziation in progress)
- Properly keeping a set epsilon region when colliding (TODO)
- Handling sliding better (TODO)

# Build instructions
- Clone using git clone --recursive (to pull dependency for ImGui and glm)
- Build using CMake
```
mkdir build
cd build
cmake ../src
cmake --build .
```
- Note dependencies on pkgconfig and GLFW
