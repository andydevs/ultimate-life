cmake_minimum_required(VERSION 3.22)
project(ultimate_life)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(LIFESCRIPT_GENERATE_PARSERS "Generate lifescript parsers using ANTLR (Requires ANTLRv4)" OFF)
option(ULTIMATE_LIFE_BUILD_TESTS   "Build google test project" OFF)

# Fix MSVC Static Linking
if (MSVC)
    message(STATUS "Building using MSVC")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif(MSVC)
if(UNIX)
    message(STATUS "Building using CLANG")
    set(CMAKE_C_LINKER_FLAGS "-std=c11")
    set(CMAKE_CXX_LINKER_FLAGS "-std=c++11")
endif()


# Fetch required dependencies
include(FetchContent)
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG        98d1f3a45aae568ccd6ed5fec179330f47d4d356 # release-2.32.8
)
FetchContent_Declare(
    ANTLR4_RUNTIME
    GIT_REPOSITORY https://github.com/antlr/antlr4.git
    GIT_TAG        faa457ae5b9c39b572334814f0b36c855bc23010 # Latest as of Dec 13 2025
    SOURCE_SUBDIR  runtime/Cpp
)
FetchContent_MakeAvailable(SDL2 ANTLR4_RUNTIME)

# Life Script Parsers
set(LS_PARSER_NAME LifeScript)
set(LS_PARSER_PATH ${PROJECT_SOURCE_DIR}/src/lifescript)
set(LS_GENERATED_DIR generated)
set(LS_GENERATED_PATH ${LS_PARSER_PATH}/${LS_GENERATED_DIR})
set(LS_PARSER_SRC 
    ${LS_GENERATED_PATH}/${LS_PARSER_NAME}Lexer.cpp
    ${LS_GENERATED_PATH}/${LS_PARSER_NAME}Parser.cpp
    ${LS_GENERATED_PATH}/${LS_PARSER_NAME}Visitor.cpp
    ${LS_GENERATED_PATH}/${LS_PARSER_NAME}BaseVisitor.cpp)

# Generate command based on option
if(LIFESCRIPT_GENERATE_PARSERS)
message(STATUS "Will regenerate LifeScript parsers at build time")
    # Find ANTLR. Make sure we got it in our system
    find_program(ANTLR4 antlr4 antlr)
    if (NOT ANTLR4)
        message(FATAL_ERROR "Executable for ANTLR4 was not found! This is required to regenerate parsers. 
Either make sure ANTLRv4 is installed in your system (See README.md) or disable parser generating 
(-DLIFESCRIPT_GENERATE_PARSERS=OFF)")
    endif(NOT ANTLR4)
    message(STATUS "ANTLR4 Located (Program Location: ${ANTLR4})")

    # Declare lifescript parser generation command
    file(MAKE_DIRECTORY "${LS_GENERATED_PATH}")
    foreach(ls_parser_file ${LS_PARSER_SRC})
        set_property(SOURCE ${ls_parser_file} PROPERTY GENERATED TRUE)
    endforeach(ls_parser_file ${LS_PARSER_SRC})
    add_custom_command(OUTPUT ${LS_PARSER_SRC}
                    COMMAND
                    antlr4 -no-listener -visitor ${LS_PARSER_NAME}.g4 -o ${LS_GENERATED_DIR}/
                    DEPENDS
                    LifeScript.g4
                    WORKING_DIRECTORY
                    ${LS_PARSER_PATH})
endif(LIFESCRIPT_GENERATE_PARSERS)

# Include directory
include_directories(include)

# Utils library
file(GLOB UTILS_LIB_SRC src/utils/*.cpp)
add_library(utils ${UTILS_LIB_SRC})

# LifeScript Library
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
add_executable(ultimate_life ${UL_EXE_SRC})
target_link_libraries(ultimate_life utils lifescript raiisdl)
install(TARGETS ultimate_life)

# Ultimate Life Test Suite
if(ULTIMATE_LIFE_BUILD_TESTS)
    # Fetch and include GTest
    FetchContent_Declare(
        GoogleTest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        52eb8108c5bdec04579160ae17225d66034bd723 # release-1.17.0
    )
    FetchContent_MakeAvailable(GoogleTest)

    # Test suite target
    file(GLOB UL_TEST_SRC tests/*.cpp)
    add_executable(test_ultimate_life ${UL_TEST_SRC})
    target_link_libraries(test_ultimate_life gtest_main utils lifescript)
    
    # Enable testing
    enable_testing()
    include(GoogleTest)
    gtest_discover_tests(test_ultimate_life)
endif(ULTIMATE_LIFE_BUILD_TESTS)