// Interpolacja dwuliniowa w siatce 

// Standard headers
#include <iostream>
#include <vector>

// Thierd Party headers
#include <opencv2/opencv.hpp>


// Function Definitions

int bilinear_interpolation(int, int, std::string);
cv::Vec3b interpolate(cv::Mat, float, float);
cv::Mat resize(cv::Mat, int, int);


