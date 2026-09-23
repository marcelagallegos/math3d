include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v3.16.0
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests vec.test.cpp)
target_link_libraries(tests PRIVATE math3d::math3d Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(tests)
