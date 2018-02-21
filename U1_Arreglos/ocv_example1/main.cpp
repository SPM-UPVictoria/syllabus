#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void onMouse(int event, int x, int y, int flags, void* param);

int main ()
{
    Mat image;

    cout << "This image is " << image.rows << " x " << image.cols << endl;

    //image = imread("puppy.jpg", IMREAD_COLOR); // read an input image
    image = imread("puppy.jpg", IMREAD_GRAYSCALE);

    if (image.empty()) {
        cerr << "se econtró un error al abrir la imagen" << endl;
    }
    else {

        circle(image,               // destination image
               Point(155,110),       // center coordinate
               65,                  // radius
               0,                   // color (here black
               3);

        putText(image,              // destination image
                "This is a dog.",   // text
                Point(230, 500),     // text position
                FONT_HERSHEY_PLAIN,  // font type
                2.0,                // font scale
                255,                // text color (here white)
                2);                 // text thickness

        //define the window (optional)
        namedWindow("Original Image");
        // show the image
        imshow("Original Image", image);

        setMouseCallback("Original Image", onMouse, reinterpret_cast<void*>(&image));



        cout << "this image has " << image.channels() << " channel(s)" << endl;

        //Mat result; // we create another empty image

        //flip(image, result, 1); // positive for horiontal
                                // 0 for vertical
                                // negative for both
        //namedWindow("Result Image"); // hte output window
        //imshow("Result Image", result);

        //imwrite("result.jpg", result); // save result
    }

    waitKey(0);
    return 0;
}

void onMouse(int event, int x, int y, int flags, void* param)
{
    Mat *im = reinterpret_cast<Mat*>(param);

    switch(event)   //dispatch the event
    {
        case EVENT_LBUTTONDOWN: // left mouse button down event
            //display pixel value at (x, y)
            cout << "at (" << x << ", " << y << ") value is: " << static_cast<int> (im->at<uchar>(Point(x,y))) << endl;
            break;
    }
}
