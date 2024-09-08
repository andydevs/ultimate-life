from conan import ConanFile
from conan.tools.cmake import cmake_layout

class UltimateLife(ConanFile):
    name = 'ultimate-life'
    version = '0.1.0'
    settings = 'os', 'arch', 'compiler', 'build_type'
    generators = 'CMakeDeps', 'CMakeToolchain'

    def build_requirements(self):
        self.tool_requires('cmake/[>=3.22]')
        self.tool_requires('antlr4/[>=4.13]')

    def requirements(self):
        self.requires("sdl/2.30.6")
        self.requires("antlr4-cppruntime/[>=4.13]")

    def layout(self):
        cmake_layout(self)