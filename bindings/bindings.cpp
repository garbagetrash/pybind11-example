#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <numeric>
#include <vector>
#include "lib.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pylib, m) {
  m.doc() = "Example python bindings for a C++ library";

  m.def("mean", &lib::mean, "Calculate the mean of an array of values");
  m.def("summer", [](const std::vector<double> &v) {return std::accumulate(v.begin(), v.end(), 0);});
}
