// Generowanie sygnałów o zadanej częstotliwości (sin, cos, prostokątny, piłokształtny)


// Standard headers
#include <vector>
#include <cmath>
#include <iostream>

// Thierd Party headers
#include <matplot/matplot.h>
#include "AudioFile.h"
#define M_PI 3.14159265358979323846



// Function Definitions

class Generator {
public:
    static void sinusoidalSignal(double, double);
    static void cosinusoidalSignal(double, double);
    static void squareWaveSignal(double, double);
    static void sawtoothWaveSignal(double, double);

};

