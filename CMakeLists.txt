cmake_minimum_required(VERSION 3.16)
project(venusblast LANGUAGES CXX)

set(CMAKE_CXX_COMPILER "g++")
include_directories(src)
add_compile_options(-std=c++17)
link_libraries(sfml-graphics sfml-audio sfml-system sfml-window)

add_executable(venusblast)

add_subdirectory(src)
