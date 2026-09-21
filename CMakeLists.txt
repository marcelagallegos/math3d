cmake_minimum_required(VERSION 3.22)

project(math3d LANGUAGES CXX)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are not allowed.")
endif()

add_library(math3d INTERFACE)
add_library(math3d::math3d ALIAS math3d)

target_compile_features(math3d INTERFACE cxx_std_20)
target_include_directories(math3d INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
