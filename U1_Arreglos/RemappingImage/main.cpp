#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

void wave(const Mat &image, Mat &result);

int main(int argc, char *argv[])
{
    Mat img = imread("lena.jpg", CV_LOAD_IMAGE_COLOR);
    if(img.empty())
       return -1;
    Mat res;

    wave(img, res);

    namedWindow( "lena", CV_WINDOW_AUTOSIZE );
    imshow("lena", res);
    waitKey(0);
    return 0;
}

void wave(const Mat &image, Mat &result)
{
    // imagenes para las funciones de mapeo
    Mat srcX(image.rows, image.cols, CV_32F);
    Mat srcY(image.rows, image.cols, CV_32F);

    //creamos el mapeo
    for (int i=0; i<image.rows; i++)
    {
        for (int j=0; j < image.cols; j++)
        {
            //nueva posición del pixel en (i,j)
            srcX.at<float>(i,j) = j; //mantenemos la misma columna
                                    // pixeles de las filas i son movidas
                                    // de acuedo a una sinusoidal
            srcY.at<float>(i,j) = i + 5 * sin(j/10.0);
        }
    }

    // aplicamos el mapeo
    remap(image,    // imagen original
          result,   // imagen destino
          srcX,     // mapeo en x
          srcY,     // mapeo eny
          INTER_LINEAR);    //método de interpolación
}



