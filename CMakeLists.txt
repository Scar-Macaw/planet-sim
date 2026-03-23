 cmake_minimum_required(VERSION 3.16)
project(PlanetSim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master
)

FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE _SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(PlanetSim ${_SOURCES})

target_link_libraries(PlanetSim raylib)