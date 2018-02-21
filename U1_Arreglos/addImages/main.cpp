#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int main(int argc, char *argv[])
{
    Mat image1;
    Mat image2;

    //abrimos y verificamos
    image1 = imread("boldt.jpg");
    image2 = imread("rain.jpg");

    if (!image1.data)
        return 0;
    if (!image2.data)
        return 0;

    namedWindow("Image 1");
    imshow("Image 1", image1);
    namedWindow("Image 2");
    imshow("Image 2", image2);

    waitKey(0);

    Mat result;

    //sumamos las dos imagenes
    addWeighted(image1, 0.7, image2, 0.9, 0., result);

    namedWindow("result");
    imshow("result",result);
    waitKey(0);

    // utilizando la sobrecarga de operadores
    Mat res2;

    res2 = 0.7*image1 + 0.9*image2;

    namedWindow("Result with operators");
    imshow("Result with operators", res2);

    waitKey(0);

    // separación de los 3 canales de la imagen

    image2 = imread("rain.jpg",0);

    //creamos un vector de tres imagenes
    std::vector<Mat> planes;
    split(image1, planes);

    namedWindow("Red");
    imshow("Red",planes[0]);
    namedWindow("Blue");
    imshow("Blue",planes[1]);
    namedWindow("Green");
    imshow("Green",planes[2]);
    //sumamos al canal azul
    planes[0] += image2;

    merge(planes, result);

    namedWindow("Result on blue channel");
    imshow("Result on blue channel", result);

    waitKey(0);
}



