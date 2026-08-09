cmake_minimum_required(VERSION 3.20)

project(ex4_op_count LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ex4_op_count
    app/main.cpp
    src/op_count.cpp
    header/op_count.h
)

target_include_directories(ex4_op_count PRIVATE header)
