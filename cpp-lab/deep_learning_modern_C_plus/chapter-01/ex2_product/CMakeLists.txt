cmake_minimum_required(VERSION 3.20)

project(ex2_product LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ex2_product
    app/main.cpp
    src/product.cpp
    header/product.h
)

target_include_directories(ex2_product PRIVATE header)
