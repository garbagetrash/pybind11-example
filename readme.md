pybind11 Bindings Example
=========================

This repo is meant to be used as a template or example to get started with
creating python bindings for C++ projects using
[pybind11](https://github.com/pybind/pybind11) and [cmake](https://cmake.org/).

Build
-----

Build by simply doing:

```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Now you should be able to `import bindings` in a python REPL from the `build`
directory.
