// Szymon Kowalski 198055
// Sebastian Kuczera 198108
// acir2 
// techniki programowania - Projekt 3



// Thired Party headers
#include <pybind11/pybind11.h>


// Local headers
#include "audio_visualization.hpp"
#include "signal_generator.hpp"
#include "Bilinear_interpolation.hpp"
#include "signal_filtration.hpp"


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
    m.def("bilinear_interpolation", &bilinear_interpolation, "bilinear interpolation using opencv");
    m.def("signal_filtration", &signal_filtration, "Signal Filtration using opencv");
    

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
