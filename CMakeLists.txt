cmake_minimum_required(VERSION 3.4)
project(pylib)

# First we build our library we want to add bindings to
add_subdirectory(library)

# Now create our bindings
add_subdirectory(pybind11)
pybind11_add_module(pylib
  ${CMAKE_CURRENT_SOURCE_DIR}/bindings/bindings.cpp
)
target_include_directories(pylib
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/library/include
)
target_link_libraries(pylib
  PUBLIC library
)
