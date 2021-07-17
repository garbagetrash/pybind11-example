#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "lib.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pylib, m) {
  m.doc() = "Example python bindings for a C++ library";

  m.def("mean", &mean, "Calculate the mean of an array of values");
}
