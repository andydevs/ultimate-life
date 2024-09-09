#!/bin/bash
build_type=$(conan profile show | grep -E 'build_type=(\w+)' | head -n1 | sed 's/build_type=//')
conan install . --build=missing
source build/$build_type/generators/conanbuild.sh
cmake --preset conan-release
cmake --build --preset conan-release
cmake --install build/$build_type