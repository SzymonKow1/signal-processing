#include "signal_filtration.hpp"


cv::Mat redFilter(cv::Mat src)
{
    cv::Mat dst = src.clone();


    for (int i = 0; i < dst.rows; i++)
    {
        for (int j = 0; j < dst.cols; j++)
        {
            cv::Vec3b pixel = dst.at<cv::Vec3b>(i, j);

            float newBlue, newGreen, newRed;

            newBlue = cv::saturatecast<uchar>(pixel[2] * 2);
            newGreen = cv::saturate_cast<uchar>(pixel[2] * 2);
            newRed = cv::saturate_cast<uchar>(pixel[2] * 3);

            dst.at<cv::Vec3b>(i, j) = cv::Vec3b(newBlue, newGreen, newRed);
        }
    }
    return dst;
}

cv::Mat blurFilter(cv::Mat src)
{
    cv::Mat dst;
    return cv::blur(src, dst, cv::Size(5, 5));
}

cv::Mat sharpenedFilter(cv::Mat src)
{
    cv::Mat kernel = (cv::Mat<float>(3, 3) <<
                      0, -1, 0,
                      -1, 5, -1,
                      0, -1, 0);

    cv::Mat dst;
    cv::filter2D(src, dst, -1, kernel);
}


int signal_filtration(std::string fileName)
{
    cv::Mat src = cv::imread(fileName);

    if (src.empty()) 
    {
        std::cerr << "Can't load file" << std::endl;
        return -1;
    }

    cv::Mat redSrc = redFilter(src);
    cv::Mat sharpenedSrc = sharpenedFilter(src);
    cv::Mat bluredSrc = blurFilter(src);

    cv::imshow("Original", src);

    cv::imshow("sharp", sharpenedSrc);
    cv::imshow("Blured", bluredSrc);
    cv::imshow("red", redSrc);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}