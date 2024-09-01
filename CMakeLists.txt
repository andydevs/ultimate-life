cmake_minimum_required(VERSION 3.22)
project(ultimate_life)

find_package(SDL2)

add_executable(ultimate_life 
    src/ultimate_life/main.cpp)

target_link_libraries(ultimate_life SDL2::SDL2-static)