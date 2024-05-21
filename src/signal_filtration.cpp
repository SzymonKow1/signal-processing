#include "signal_filtration.hpp"

// custom filltration
cv::Mat redFilter(cv::Mat src)
{
    cv::Mat dst = src.clone();


    for (int i = 0; i < dst.rows; i++)
    {
        for (int j = 0; j < dst.cols; j++)
        {
            cv::Vec3b pixel = dst.at<cv::Vec3b>(i, j);

            float newBlue, newGreen, newRed;

            newBlue = cv::saturate_cast<uchar>(pixel[2] * 2); // saturate_cast - casting to unsigned char 
            newGreen = cv::saturate_cast<uchar>(pixel[2] * 2);
            newRed = cv::saturate_cast<uchar>(pixel[2] * 3);

            dst.at<cv::Vec3b>(i, j) = cv::Vec3b(newBlue, newGreen, newRed);
        }
    }
    return dst;
}

// 1d filltration using opencv function
cv::Mat blurFilter(cv::Mat src)
{
    cv::Mat dst;
    cv::blur(src, dst, cv::Size(5, 5));
    return dst;

}
// 2d filltration
cv::Mat sharpenedFilter(cv::Mat src)
{
    cv::Mat kernel = (cv::Mat_<float>(3, 3) <<
                      0, -1, 0,
                      -1, 5, -1,
                      0, -1, 0);

    cv::Mat dst;
    cv::filter2D(src, dst, -1, kernel);
    return dst;
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
    cv::imwrite("./img/root.jpg", src);

    cv::imshow("sharp", sharpenedSrc);
    cv::imwrite("./img/sharpenedSrc.jpg", sharpenedSrc);

    cv::imshow("Blured", bluredSrc);
    cv::imwrite("./img/bluredSrc.jpg", bluredSrc);

    cv::imshow("red", redSrc);
    cv::imwrite("./img/redSrc.jpg", redSrc);


    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}