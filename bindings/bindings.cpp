#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <numeric>
#include <vector>
#include "lib.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pylib, m) {
  m.doc() = "Example python bindings for a C++ library";

  m.def("mean", &lib::mean, "Calculate the mean of an array of values");

  m.def("iter_sum", [](std::vector<double> &v) {
        double result = lib::iter_sum(v.begin(), v.end());
        return result;
      }, "Takes iterators, returns sum of elements between them");
}
