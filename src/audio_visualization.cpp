#include "audio_visualization.hpp"

// Namespaces
namespace plt = matplot;

void visualizeAudio(int numOfSamples, std::string file)
{
    AudioFile<double> audioFile;
    audioFile.load (file);

    std::vector<double> x;
    std::vector<double> y;

    int channel = 0;

    for(int i = 0; i < numOfSamples; i++)
    {
        x.push_back(i);
        y.push_back(audioFile.samples[channel][i]);
    }

    plt::plot(x, y, "-o");

    plt::show();
}