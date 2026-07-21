cmake_minimum_required(VERSION 3.20)
project(cpp-lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

add_compile_options(-Wall -Wextra -Wpedantic)

# Each numbered module is added as it gains buildable sources.
add_subdirectory(01_basics)
add_subdirectory(02_stl)
add_subdirectory(03_oop)
add_subdirectory(04_templates)
add_subdirectory(05_smart_pointers)
add_subdirectory(06_concurrency)
add_subdirectory(07_memory)
add_subdirectory(08_cpp20)
add_subdirectory(09_design_patterns)
add_subdirectory(10_projects)
