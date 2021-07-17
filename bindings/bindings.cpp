#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <complex>
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

  py::class_<lib::BitsGen>(m, "BitsGen")
    .def(py::init<>())
    .def("set_seed", &lib::BitsGen::set_seed)
    .def("yield_bit", &lib::BitsGen::yield_bit)
    .def("yield_byte", &lib::BitsGen::yield_byte)
    .def("yield_n_bits", &lib::BitsGen::yield_n_bits)
    .def("yield_n_bytes", &lib::BitsGen::yield_n_bytes);

  m.def("bpsk_mod", &lib::bpsk_mod, "BPSK modulation of the input vector of bits");
}
