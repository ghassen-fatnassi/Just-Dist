cmake_minimum_required(VERSION 3.18)
project(JustDist LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to libtorch (downloaded & extracted into your project root)
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/libtorch")

# Find libtorch
find_package(Torch REQUIRED)

# Include your project headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Collect source files recursively
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# Create executable
add_executable(just_dist ${SOURCES})

# Link libtorch libraries
target_link_libraries(just_dist "${TORCH_LIBRARIES}")

# Ensure C++17 for the target
set_property(TARGET just_dist PROPERTY CXX_STANDARD 17)

# (Optional) Export compile commands for VSCode/clangd/etc.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
