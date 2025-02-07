cmake_minimum_required(VERSION 3.10)
project(Raytracing)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL3 REQUIRED PATHS "${PROJECT_SOURCE_DIR}/deps/SDL3-3.2.2/build")

# Add the library
add_subdirectory(src)

# Add the demo
add_subdirectory(demo)