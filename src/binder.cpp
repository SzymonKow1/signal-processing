// Standard headers
#include <vector>
#include <cmath>

//local headers
#include <matplot/matplot.h>
#include <pybind11/pybind11.h>


#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)



void hello()
{
    std::cout << "Hello World!";
}

int add(int i, int j) 
{

    return i + j;
}

void plot()
{
    using namespace matplot;
    std::vector<double> x = linspace(0, 2 * pi);
    std::vector<double> y = transform(x, [](auto x) { return cos(x); });

    plot(x, y, "-o");
    hold(on);
    plot(x, transform(y, [](auto y) { return -y; }), "--xr");
    plot(x, transform(x, [](auto x) { return x / pi - 1.; }), "-:gs");
    plot({1.0, 0.7, 0.4, 0.0, -0.4, -0.7, -1}, "k");

    show();
}

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: scikit_build_example

        .. autosummary::
           :toctree: _generate

           add
           subtract
           plot
    )pbdoc";

    m.def("add", &add, " Add two numbers ");

    m.def("subtract", [](int i, int j) { return i - j; }, "Subtract two numbers");

    m.def("plot", &plot, "Plot using matplot");

    m.def("hello", &hello, "Hello World!");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
