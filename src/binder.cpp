// Standard headers
// ...

// Thired Party headers
#include <pybind11/pybind11.h>

// Local headers
#include "audio_visualization.hpp"


#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


namespace py = pybind11;

// PyBind11 Mudule 
PYBIND11_MODULE(_core, m) {
    
    m.def("visualizeAudio", &visualizeAudio, "Audio visualization using matplot & AudioFile.h");


#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
