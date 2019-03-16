message(STATUS "Maze on paper")
cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 11)

set(BINARY_DIR ${CMAKE_BINARY_DIR}/bin)
set(CmakeHelpers ${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers)
include(${CmakeHelpers}/default_component_structure.cmake)

add_subdirectory(components)
add_subdirectory(ui)