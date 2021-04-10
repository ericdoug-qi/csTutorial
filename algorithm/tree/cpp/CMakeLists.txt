cmake_minimum_required(VERSION 2.6)
project(tree)
set(CMAKE_CXX_STANDARD 11)

add_executable(bin_tree bin_tree.cpp)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

