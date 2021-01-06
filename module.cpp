#include <pybind11/pybind11.h>

// vector2
#include <math.h>
#include <iostream>

// Class definition
class vector2 
{
public:
    double x, y;

    // Constructors
    vector2();
    vector2(double x, double y);

    // Functions
    double dotProduct(vector2& other) const;
    double magnitude();
};


// Constructor without parameters
vector2::vector2()
{
    x = 0;
    y = 0;
}

// Contstructor with paramters
vector2::vector2(double x, double y)
{
    this->x = x;
    this->y = y;
}

// Funtion declaration
// dotProduct
double vector2::dotProduct(vector2& other) const
{
    return this->x * other.x + this->y * other.y;
}

// magnitude
double vector2::magnitude()
{
    return std::sqrt(this->dotProduct(*this));
}


// PYBIND11

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/functional.h>

namespace py = pybind11;

PYBIND11_MODULE(cshape, m) {
    // module docstring
    m.doc() = "cshape";


    py::class_<vector2>(m, "vector2")
        .def(py::init())
        .def(py::init<double &, double>())
        .def("dotProduct", &vector2::dotProduct)
        .def("magnitude", &vector2::magnitude)
        .def_readwrite("x", &vector2::x)
        .def_readwrite("y", &vector2::y);
        
}
