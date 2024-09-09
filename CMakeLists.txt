cmake_minimum_required(VERSION 3.22)
project(ultimate_life)

set(CMAKE_CXX_STANDARD_REQUIRED 17)

find_package(SDL2)
find_package(antlr4-runtime)
include_directories(include)

file(GLOB LS_LIB_SRC src/lifescript/*.cpp)
add_library(lifescript ${LS_LIB_SRC})
target_link_libraries(lifescript antlr4_static)

file(GLOB UL_EXE_SRC src/ultimate_life/*.cpp)
add_executable(ultimate_life ${UL_EXE_SRC})
target_include_directories(ultimate_life PUBLIC src/lifescript)
target_link_libraries(ultimate_life SDL2::SDL2-static antlr4_static lifescript)