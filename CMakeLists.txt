cmake_minimum_required(VERSION 3.22)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are not allowed.")
endif()

project(math3d LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(math3d INTERFACE)
add_library(math3d::math3d ALIAS math3d)

target_compile_features(math3d INTERFACE cxx_std_20)
target_include_directories(
    math3d
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(PROJECT_IS_TOP_LEVEL)
    include(CTest)
    add_subdirectory(tests)
endif()
