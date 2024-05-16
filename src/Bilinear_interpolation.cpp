#include "Bilinear_interpolation.hpp"


int bilinear_interpolation(int newWidth, int newHeight, std::string fileName)
{
    cv::Mat src = cv::imread(fileName);

    if (src.empty()) 
    {
        std::cerr << "Can't load file" << std::endl;
        return -1;
    }


    cv::Mat scaled = resize(src, newWidth, newHeight);

    cv::imshow("Original", src);
    cv::imshow("Scaled", scaled);

    

    cv::waitKey(0);
    return 0;
}


cv::Vec3b interpolite(cv::Mat src, float x, float y)
{
    int xf = std::floor(x);
    int yf = std::floor(y);
    int xc = std::ceil(x);
    int yc = std::ceil(y);

    if (xc >= src.cols) xc = src.cols - 1;

    if (yc >= src.rows) yc = src.rows - 1;

    cv::Vec3b pixel_ff = src.at<cv::Vec3b>(yf, xf);
    cv::Vec3b pixel_fc = src.at<cv::Vec3b>(yf, xc);
    cv::Vec3b pixel_cf = src.at<cv::Vec3b>(yc, xf);
    cv::Vec3b pixel_cc = src.at<cv::Vec3b>(yc, xc);

    float dx = x - xf;
    float dy = y - yf;
    cv::Vec3b interpolizedPixel;
    for (int i = 0; i < 3 ; i++)
    {
        interpolizedPixel[i] = (1 - dx) * (1 - dy) * pixel_ff[i] +
                               dx       * (1 - dy) * pixel_fc[i] +
                               (1 - dx) * dy       * pixel_cf[i] +
                               dx       * dy       * pixel_cc[i];
    } 
    return interpolizedPixel;

}

cv::Mat resize(cv::Mat src, int newWidth, int newHeight)
{
    cv::Mat nsrc(newHeight, newWidth, src.type());

    float xRatio = static_cast<float>(src.cols - 1) / (newWidth - 1);
    float yRatio = static_cast<float>(src.rows - 1) / (newHeight - 1);

    for(int i = 0; i < nsrc.rows; i++)
    {
        for(int j = 0; j < nsrc.cols; j++)
        {
            float x = j * xRatio;
            float y = i * yRatio;
            nsrc.at<cv::Vec3b>(i, j) =  interpolite(src, x, y);
        }

    }
    return nsrc;

}