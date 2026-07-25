cmake_minimum_required(VERSION 3.20)

project(TinyVision
  VERSION 0.1.0
  DESCRIPTION "A Modern C++20 image processing learning library"
  LANGUAGES CXX)

# ---- Standard ---------------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

set(TINYVISION_IS_TOP_LEVEL OFF)
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set(TINYVISION_IS_TOP_LEVEL ON)
endif()

# ---- Options ----------------------------------------------------------------
option(TINYVISION_BUILD_EXAMPLES     "Build example programs"   ${TINYVISION_IS_TOP_LEVEL})
option(TINYVISION_BUILD_TESTS        "Build unit tests"         ${TINYVISION_IS_TOP_LEVEL})
option(TINYVISION_BUILD_BENCHMARKS   "Build benchmarks"         OFF)
option(TINYVISION_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)

# ---- Warnings ---------------------------------------------------------------
if(MSVC)
  set(TINYVISION_WARNINGS /W4)
else()
  set(TINYVISION_WARNINGS -Wall -Wextra -Wpedantic -Wshadow -Wconversion)
endif()
if(TINYVISION_WARNINGS_AS_ERRORS)
  list(APPEND TINYVISION_WARNINGS $<IF:$<BOOL:${MSVC}>,/WX,-Werror>)
endif()

# ---- Library ----------------------------------------------------------------
# Collect implementation sources from src/. While src/ holds only headers'
# stubs the list is empty, so the library is exposed as header-only (INTERFACE).
# It automatically becomes a compiled STATIC library once real .cpp files land.
file(GLOB_RECURSE TINYVISION_SOURCES CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

if(TINYVISION_SOURCES)
  add_library(tinyvision STATIC ${TINYVISION_SOURCES})
  target_compile_options(tinyvision PRIVATE ${TINYVISION_WARNINGS})
else()
  add_library(tinyvision INTERFACE)
endif()
add_library(TinyVision::tinyvision ALIAS tinyvision)

if(TINYVISION_SOURCES)
  set(_tv_scope PUBLIC)
else()
  set(_tv_scope INTERFACE)
endif()

target_include_directories(tinyvision ${_tv_scope}
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(tinyvision ${_tv_scope} cxx_std_20)

# ---- Examples ---------------------------------------------------------------
if(TINYVISION_BUILD_EXAMPLES)
  file(GLOB TINYVISION_EXAMPLES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
  foreach(_ex ${TINYVISION_EXAMPLES})
    get_filename_component(_name "${_ex}" NAME_WE)
    add_executable(${_name} "${_ex}")
    target_link_libraries(${_name} PRIVATE tinyvision)
    target_compile_options(${_name} PRIVATE ${TINYVISION_WARNINGS})
  endforeach()
endif()

# ---- Tests / benchmarks -----------------------------------------------------
if(TINYVISION_BUILD_TESTS AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/CMakeLists.txt")
  enable_testing()
  add_subdirectory(tests)
endif()

if(TINYVISION_BUILD_BENCHMARKS AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/benchmark/CMakeLists.txt")
  add_subdirectory(benchmark)
endif()
