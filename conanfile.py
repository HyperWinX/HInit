from conan import ConanFile
from conan.tools.cmake import cmake_layout

class HInit(ConanFile):
    name = "HInit"
    version = "0.0.0"
    settings = ["os", "compiler", "build_type", "arch"]
    author = "HyperWinX"
    requires = [
        "boost/1.87.0"
    ]
    generators = ["CMakeToolchain", "CMakeDeps"]

    def layout(self) -> None:
        cmake_layout(self)