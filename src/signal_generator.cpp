#include "signal_generator.hpp"

// Namespaces
namespace plt = matplot;



void Generator::sinusoidalSignal(double duration, double frequency)
{
    double sample_rate = 100.0;

    std::vector<double> x;
    std::vector<double> y;

    double t = 0.0;
    for (int i = 0; i < sample_rate * duration; ++i) {

        t = i / sample_rate;

        x.push_back(t);
        y.push_back(sin(2 * M_PI * frequency * t));
        
    }

    plt::plot(x, y, "-o");
    plt::show();
}

void Generator::cosinusoidalSignal(double duration, double frequency)
{
    double sample_rate = 100.0;

    std::vector<double> x;
    std::vector<double> y;

    double t = 0.0;
    for (int i = 0; i < sample_rate * duration; ++i) {

        t = i / sample_rate;

        x.push_back(t);
        y.push_back(cos(2 * M_PI * frequency * t));
        
    }

    plt::plot(x, y, "-o");
    plt::show();
}

void Generator::squareWaveSignal(double duration, double frequency)
{
    double sample_rate = 100.0;

    std::vector<double> x;
    std::vector<double> y;

    double t = 0.0;
    for (int i = 0; i < sample_rate * duration; ++i) {

        t = i / sample_rate;

        x.push_back(t);        
        if (fmod(t * frequency, 1.0) < 0.5)
            y.push_back(0.5);
        else
            y.push_back(-0.5);
    }

    plt::plot(x, y, "-o");
    plt::show();
}

void Generator::sawtoothWaveSignal(double duration, double frequency)
{
    double sample_rate = 100.0;
    double half_period = 0.0;
    std::vector<double> x;
    std::vector<double> y;

    double t = 0.0;
    for (int i = 0; i < sample_rate * duration; ++i) {

        t = i / sample_rate;
        half_period = fmod(t * frequency, 1.0);

        x.push_back(t);        
        if (half_period < 0.5)
        {
            y.push_back(2.0 * half_period);
        }
        else
        {
            y.push_back(2.0 * (half_period - 1.0));        
        }
        
    }

    plt::plot(x, y, "-o");
    plt::show();
}



