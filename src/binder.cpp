// Standard headers
// ...

// Thired Party headers
#include <pybind11/pybind11.h>

// Local headers
#include "audio_visualization.hpp"
#include "signal_generator.hpp"


#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


namespace py = pybind11;

// PyBind11 Mudule 

PYBIND11_MODULE(_core, m) {
    
    m.def("visualizeAudio", &visualizeAudio, "Audio visualization using matplot & AudioFile.h");
    m.def("sinusoidalSignal", &Generator::sinusoidalSignal, "Sinusoidal Signal Generator");
    m.def("cosinusoidalSignal", &Generator::cosinusoidalSignal, "Cosinusoidal Signal Generator");
    m.def("squareWaveSignal", &Generator::squareWaveSignal, "Square Wave Signal Generator");
    m.def("sawtoothWaveSignal", &Generator::sawtoothWaveSignal, "Sawtooth Wave Signal Generator");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
