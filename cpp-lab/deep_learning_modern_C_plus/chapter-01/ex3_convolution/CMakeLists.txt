cmake_minimum_required(VERSION 3.20)

project(ex3_convolution LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ex3_convolution
    app/main.cpp
    src/convolution.cpp
    header/convolution.h
)

target_include_directories(ex3_convolution PRIVATE header)
