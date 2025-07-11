cmake_minimum_required(VERSION 3.18)
project(JustDist LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "../libtorch")  # Path to libtorch extracted dir

find_package(Torch REQUIRED)

include_directories(include)

file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/comm/*.cpp
    src/scheduler/*.cpp
)

add_executable(just_dist ${SOURCES})
target_link_libraries(just_dist "${TORCH_LIBRARIES}")
set_property(TARGET just_dist PROPERTY CXX_STANDARD 17)
