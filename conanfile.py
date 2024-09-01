from conan import ConanFile
from conan.tools.cmake import cmake_layout

class UltimateLife(ConanFile):
    name = 'ultimate-life'
    version = '0.1.0'
    settings = 'os', 'arch', 'compiler', 'build_type'
    generators = 'CMakeDeps', 'CMakeToolchain'

    def requirements(self):
        self.requires("sdl/2.30.6")

    def layout(self):
        cmake_layout(self)