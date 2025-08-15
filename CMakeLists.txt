cmake_minimum_required(VERSION 3.28)

project(HInit LANGUAGES CXX VERSION 0.0.0)

find_package(spdlog)

set(CMAKE_CXX_FLAGS "-Wno-write-strings")

add_executable(hinit-core src/Core/Main.cpp
        src/Ctl/Main.cpp
        src/Core/Steps/Mounts.cpp
        src/Core/Steps/SetupDev.cpp
        src/Core/Steps/SetupUdevd.cpp
        src/Core/Steps/StartDhcpcd.cpp)
target_include_directories(hinit-core PUBLIC src/Core PUBLIC src/Utils)
target_link_libraries(hinit-core spdlog::spdlog)
