message(STATUS "Maze on paper")
cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 11)

set(CmakeHelpers ${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers)
add_subdirectory(components)
