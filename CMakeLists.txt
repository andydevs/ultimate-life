cmake_minimum_required(VERSION 3.22)
project(ultimate_life)

set(CMAKE_CXX_STANDARD_REQUIRED 17)

find_package(SDL2 REQUIRED)
find_package(antlr4-runtime REQUIRED)
find_package(GTest REQUIRED)
include_directories(include)

# Utils library
file(GLOB UTILS_LIB_SRC src/utils/*.cpp)
add_library(utils ${UTILS_LIB_SRC})

# Life Script
set(LS_PARSER_NAME LifeScript)
set(LS_PARSER_PATH ${PROJECT_SOURCE_DIR}/src/lifescript)
set(LS_GENERATED_DIR generated)
set(LS_GENERATED_PATH ${LS_PARSER_PATH}/${LS_GENERATED_DIR})
set(LS_PARSER_SRC 
    ${LS_GENERATED_PATH}/${LS_PARSER_NAME}Lexer.cpp
    ${LS_GENERATED_PATH}/${LS_PARSER_NAME}Parser.cpp
    ${LS_GENERATED_PATH}/${LS_PARSER_NAME}Visitor.cpp
    ${LS_GENERATED_PATH}/${LS_PARSER_NAME}BaseVisitor.cpp)
file(MAKE_DIRECTORY "${LS_GENERATED_PATH}")
foreach(ls_parser_file ${LS_PARSER_SRC})
    set_property(SOURCE ${ls_parser_file} PROPERTY GENERATED TRUE)
endforeach(ls_parser_file ${LS_PARSER_SRC})
add_custom_command(OUTPUT ${LS_PARSER_SRC}
                   COMMAND
                   antlr4 -no-listener -visitor ${LS_PARSER_NAME}.g4 -o ${LS_GENERATED_DIR}/
                   WORKING_DIRECTORY
                   ${LS_PARSER_PATH})
file(GLOB LC_SRC ${PROJECT_SOURCE_DIR}/src/lifescript/*.cpp)
add_library(lifescript ${LS_PARSER_SRC} ${LC_SRC})
target_include_directories(lifescript PUBLIC src/lifescript/generated)
target_link_libraries(lifescript antlr4_static)

# RAII SDL Library
file(GLOB RAIISDL_SRC src/raiisdl/*.cpp)
add_library(raiisdl ${RAIISDL_SRC})
target_link_libraries(raiisdl SDL2::SDL2-static)

# Ultimate Life EXE
file(GLOB UL_EXE_SRC src/ultimate_life/*.cpp)
message(${UL_EXE_SRC})
add_executable(ultimate_life ${UL_EXE_SRC})
target_link_libraries(ultimate_life utils lifescript raiisdl)
install(TARGETS ultimate_life)

# Ultimate Life Test Suite
file(GLOB UL_TEST_SRC tests/*.cpp)
add_executable(test_ultimate_life ${UL_TEST_SRC})
target_link_libraries(test_ultimate_life gtest::gtest utils lifescript)
enable_testing()
include(GoogleTest)
gtest_discover_tests(test_ultimate_life)