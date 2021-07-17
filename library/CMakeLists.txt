cmake_minimum_required(VERSION 3.0)
project(library)
add_library(library SHARED
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lib.cpp
)
target_include_directories(library
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
