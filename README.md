# Math3D

A lightweight, header-only C++ computer graphics mathematics library inspired by [OpenGL Mathematics (GLM)](https://github.com/g-truc/glm).

*Math3D* requires a C++20 compiler and is a platform-independent library with no dependencies.

## Installation

### CMake using FetchContent
You can add *Math3D* to your CMake project to have it automatically downloaded as a dependency.

Add the following to your `CMakeLists.txt` file:
```cmake
include(FetchContent)

FetchContent_Declare(
    math3d
    GIT_REPOSITORY https://github.com/marcelagallegos/math3d
    GIT_TAG        c1d0c70d229a50ccfbbe2aee634613f1712215d9
)

FetchContent_MakeAvailable(math3d)

target_link_libraries(<target> PRIVATE math3d::math3d)
```
