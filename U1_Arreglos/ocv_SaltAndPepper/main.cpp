#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

void salt(Mat, int);

int main()
{
    Mat image = imread("boldt.jpg", 1);

    namedWindow("Image");
    imshow("Image", image);
    waitKey(0);

    salt(image, 3000);

    imshow("Image", image);
    waitKey(0);

    return 0;
}

void salt(Mat image, int n)
{
    //C++11 randon numer generator
    default_random_engine generator;
    uniform_int_distribution<int> randomRow(0, image.rows -1);
    uniform_int_distribution<int> randomCol(0, image.cols -1);

    int i, j;
    for (int k=0; k < n; k++)
    {
        // random image coordinate
        i = randomCol(generator);
        j = randomRow(generator);

        if (image.type() == CV_8UC1) //gray-level image
        {
            //single-channel 8-bit image
            image.at<uchar>(j,i) = 255;
        }
        else
        {
            if (image.type() == CV_8UC3) // color image
            {
                //3-chnnel image
                // image.at<cv::Vec3b>(j,i)[channel]= value;
                //image.at<Vec3b>(j,i)[0] = 255;
                //image.at<Vec3b>(j,i)[1] = 255;
                //image.at<Vec3b>(j,i)[2] = 255;

                image.at<Vec3b>(j, i) = Vec3b(255,255,255);
            }
        }
    }
}
