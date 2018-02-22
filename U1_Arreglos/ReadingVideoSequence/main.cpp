#include <opencv2/opencv.hpp>

using namespace cv;

void MyCanny(Mat &img, Mat &out);

int main(int argc, char *argv[])
{
    // abrimos el archivo de video
    VideoCapture capture(0);
    // VideoCapture capture("bake.avi");

    //verificamos si se abrió correctamente
    if (!capture.isOpened())
        return 0;

    //obtenemos la velocidad de los frames
    double rate = capture.get(CV_CAP_PROP_FPS);

    bool stop(false);

    Mat frame; //frame actual
    Mat res;

    namedWindow("Extracted frame");

    // Delay entre frames en ms
    // correspondiente al videoframe rate
    int delay = 1000/rate;

    //para todos los frames en el video
    while (!stop)
    {
        if (!capture.read(frame))
            break;
        //capture >> frame;

        MyCanny(frame, res);

        imshow("Extracted frame",res);

        if (waitKey(delay) >= 0)
            stop = true;
    }

    //cerramos el video
    capture.release();
    return 0;
}


void MyCanny(Mat &img, Mat &out)
{
    //convert to gray
    if (img.channels() == 3)
        cvtColor(img, out, COLOR_BGR2GRAY);
    // calculamos canny
    Canny(out, out, 100, 500);

    //invertimos la imagen
    threshold(out, out, 128, 255, THRESH_BINARY_INV);
}
