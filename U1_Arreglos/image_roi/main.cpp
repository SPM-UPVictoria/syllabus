#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

int main()
{
    cv::Mat image = cv::imread("puppy.jpg", CV_LOAD_IMAGE_COLOR);
    cv::Mat logo = cv::imread("logo.jpg", CV_LOAD_IMAGE_COLOR);

    /*cv::Mat imageROI(image,
                     cv::Rect(image.cols - logo.cols,   // ROI coordinates
                              image.rows - logo.rows,
                              logo.cols, logo.rows));   // _ROI size

    */

    //Regios of interest using cv::Range
    cv::Mat imageROI = image(cv::Range(image.rows-logo.rows, image.rows), cv::Range(image.cols - logo.cols, image.cols));

    // insert logo
    logo.copyTo(imageROI);

    cv::imshow("image", image);
    cv::waitKey(0);

    // using masks

    cv::Mat image2 = cv::imread("puppy.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    cv::Mat logo2 = cv::imread("logo.jpg", CV_LOAD_IMAGE_GRAYSCALE);

    cv::Mat imageROI2 = image2(cv::Rect(image2.cols - logo2.cols, image2.rows - logo2.rows, logo2.cols, logo2.rows));

    //use the logo as a mask (must be gray-level)
    cv::Mat mask(logo2);

    //isert by copying only at locations of non-zero mask
    logo2.copyTo(imageROI2, mask);

    cv::imshow("image 2", image2);
    cv::waitKey(0);

    return 0;
}
