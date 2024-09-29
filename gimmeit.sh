#!/bin/bash
set -e
build_type=$(conan profile show | grep -E 'build_type=(\w+)' | head -n1 | sed 's/build_type=//')
conan install . --build=missing --conf tools.system.package_manager:mode=install
cmake --preset conan-release
cmake --build --preset conan-release
cmake --install build/$build_type