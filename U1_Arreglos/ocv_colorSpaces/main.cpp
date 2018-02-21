#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("boldt.jpg");

    namedWindow("Image");
    imshow("Image", img);
    waitKey(0);

    Mat gray_img;
    cvtColor(img, gray_img, CV_BGR2GRAY);
    imshow("Image", gray_img);
    waitKey(0);

    Mat hsv_img;
    cvtColor(img, hsv_img, CV_BGR2YUV);

    imshow("Image", hsv_img[0]);

    return 0;
}
