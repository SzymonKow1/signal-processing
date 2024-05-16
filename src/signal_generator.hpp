// Standard headers
#include <vector>
#include <cmath>
#include <iostream>

// Thierd Party headers
#include <matplot/matplot.h>
#include "AudioFile.h"
#define M_PI 3.14159265358979323846


// Local headers
// ...

// Function Definitions
//void tempSin(int, std::string);

class Generator {
public:
    static void sinusoidalSignal(double duration, double frequency);
    static void cosinusoidalSignal(double duration, double frequency);
    static void squareWaveSignal(double duration, double frequency);
    static void sawtoothWaveSignal(double duration, double frequency);

};

