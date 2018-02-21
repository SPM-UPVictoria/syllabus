#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

void sharpen(const Mat &image, Mat &result);
void sharpen2D(const Mat &image, Mat &result);

int main(int argc, char *argv[])
{
    Mat img = imread("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    Mat res, res2;
    if(img.empty())
       return -1;

    namedWindow("Original",CV_WINDOW_AUTOSIZE);
    namedWindow( "Image Result", CV_WINDOW_AUTOSIZE );
    namedWindow("sharpen2D", CV_WINDOW_AUTOSIZE);

    sharpen(img, res);
    sharpen2D(img, res2);

    imshow("Original",img);
    imshow("Image Result", res);
    imshow("sharpen2D", res2);
    waitKey(0);
    return 0;
}


void sharpen(const Mat &image, Mat &result)
{
    //creamos la imgen si fuese necesario
    result.create(image.size(), image.type());
    int nchannels = image.channels(); // obtenemos el número de canales

    //para todas las filas (omitimos la primer fila y la última)
    for (int j=1; j < image.rows-1; j++)
    {
        const uchar *previous = image.ptr<const uchar>(j-1); // fila previa
        const uchar *current = image.ptr<const uchar>(j); //fila actual
        const uchar *next = image.ptr<const uchar>(j+1); //siguiente fila

        uchar *output = result.ptr<uchar>(j); // fila de la imagen de salida

        for (int i=nchannels; i < (image.cols-1)*nchannels; i++)
        {
            //aplicamos el operador de "pasa altas o sharpenning
            //utilizamos el procesador laplaciano
            // sharpened_pixel = 5 * current - left - right - up - down
            *output++= saturate_cast<uchar>(5*current[i] - current[i-nchannels] - current[i+nchannels] - previous[i] - next[i]);
        }
    }

    // aplicamos 0 a los pixeles no procesador
    result.row(0).setTo(Scalar(0));
    result.row(result.rows-1).setTo(Scalar(0));
    result.col(0).setTo(Scalar(0));
    result.col(result.cols-1).setTo(Scalar(0));
}


void sharpen2D(const Mat &image, Mat &result)
{
    // construimos el kernel (mascara de 3x3)
    Mat kernel(3,3, CV_32F, Scalar(0));

    //asignamos los valores al kernel (Laplaciano)
    kernel.at<float>(1,1) = 5.0;
    kernel.at<float>(0,1) = -1.0;
    kernel.at<float>(2,1) = -1.0;
    kernel.at<float>(1,0) = -1.0;
    kernel.at<float>(1,2) = -1.0;

    filter2D(image, result, image.depth(), kernel);
}
