cmake_minimum_required(VERSION 3.22)
project(ultimate_life)

set(CMAKE_CXX_STANDARD_REQUIRED 17)

find_package(SDL2)
include_directories(include)

file(GLOB UL_EXE_SRC src/ultimate_life/*.cpp)
add_executable(ultimate_life ${UL_EXE_SRC})

target_link_libraries(ultimate_life SDL2::SDL2-static)