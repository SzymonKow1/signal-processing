#include "audio_visualization.hpp"

// Namespaces
namespace plt = matplot;



void plot()
{
    AudioFile<double> audioFile;

    audioFile.load ("../res/test-audio.wav");

    std::vector<double> x = plt::linspace(0, 2 * plt::pi);
    std::vector<double> y = plt::transform(x, [](auto x) { return cos(x); });

    plt::plot(x, y, "-o");
    plt::hold(plt::on);
    plt::plot(x, plt::transform(y, [](auto y) { return -y; }), "--xr");
    plt::plot(x, plt::transform(x, [](auto x) { return x / plt::pi - 1.; }), "-:gs");
    plt::plot({1.0, 0.7, 0.4, 0.0, -0.4, -0.7, -1}, "k");

    plt::show();
}