project(cshape)
cmake_minimum_required(VERSION 3.16)

add_subdirectory(externals/pybind11)

pybind11_add_module(cshape module.cpp)
