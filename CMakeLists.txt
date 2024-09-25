cmake_minimum_required(VERSION 3.22)
project(ultimate_life)

set(CMAKE_CXX_STANDARD_REQUIRED 17)

find_package(SDL2)
find_package(antlr4-runtime)
find_package(GTest)
include_directories(include)

# Utils library
file(GLOB UTILS_LIB_SRC src/utils/*.cpp)
add_library(utils ${UTILS_LIB_SRC})

# Life script parser
file(GLOB LS_LIB_SRC src/lifescript/*.cpp)
add_library(lifescript ${LS_LIB_SRC})
target_link_libraries(lifescript antlr4_static)

# Ultimate Life EXE
file(GLOB UL_EXE_SRC src/ultimate_life/*.cpp)
add_executable(ultimate_life ${UL_EXE_SRC})
target_include_directories(ultimate_life PUBLIC src/lifescript)
target_link_libraries(ultimate_life 
    SDL2::SDL2-static 
    utils
    lifescript)
install(TARGETS ultimate_life)

# Ultimate Life Test Suite
file(GLOB UL_TEST_SRC tests/*.cpp)
add_executable(test_ultimate_life ${UL_TEST_SRC})
target_link_libraries(test_ultimate_life 
    gtest::gtest
    utils)
include(GoogleTest)
gtest_discover_tests(test_ultimate_life)