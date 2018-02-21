#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

void colorReduce(Mat image, int div);
void colorReduce(const Mat image,  // input image
                 Mat &result,  //output image
                 int div);

void colorReduceMatIt(); // versión que procesa los 3 canales dentro del loop con Mat_ iterators
void colorReduceItVec3b(Mat image, int div); // versión que hace uso de l iterador Vec3b

int main(int argc, char *argv[])
{
    Mat image = imread("lena.jpg"); //leemos la imagen
    if(image.empty()) //si esta vacia salimos
       return -1;

    //clonamos la imagen (si fuese necesario mantener intacta la imagen original)
    //Mat imageClone = image.clone();

    Mat res; //creamon una nueva imagen vacia

    //colorReduce(image, 64); procesamos sobre la imagen orginal
    //Procesamos sobre el clon
    //colorReduce(imageClone, 128);

    colorReduce(image,res,64);

    namedWindow( "Image Result");
//    imshow("Image Result", imageClone);
    imshow("Image Result", res);
    waitKey(0);

    Mat imageClone = image.clone();
    colorReduce(imageClone, 128);

    imshow("Image Result", imageClone);
    waitKey(0);
    destroyWindow("Image Result");

    imageClone = image.clone();
    colorReduceItVec3b(imageClone, 64);

    imshow("Image Result", imageClone);
    waitKey(0);

    return 0;
}

void colorReduce(Mat image, int div)
{
    int nl = image.rows;  //number of lines
    int nc = image.cols * image.channels();  //total number of elements per line

    for (int j=0; j<nl; j++)
    {
        //obtenemos la dirección de la fila j
        uchar *data = image.ptr<uchar>(j);

        for (int i = 0; i < nc; i++)
        {
            // procesamos cada pixel
            //data[i] = (data[i]/div)*div + div/2;
            //*data++= *data/div*div + div/2;
            data[i] = data[i] - data[i]%div + div/2;
            //fin de procesamiento
        } //fin for
    }

}


// El procesamiento de la imagen se realiza mediante dos punteros
// esta versión utiliza imagenes de entrada y salida.
void colorReduce(const Mat image, Mat &result, int div)
{
    int nl = image.rows;  //number of lines
    int nc = image.cols;
    int nchannels = image.channels();  //total number of elements per line

    result.create(image.rows, image.cols, image.type()); //se crea una imagen del mismo tamaño y mismo tipo.



    for (int j=0; j < nl; j++)
    {

        //obtenemos la direcciòn de las fila j
        const uchar *data_in = image.ptr<uchar>(j);
        uchar *data_out = result.ptr<uchar>(j);

        for (int i=0; i < nc*nchannels; i++)
        {

            // procesamos cada pixel --------------------
            data_out[i] = data_in[i]/div*div + div/2;

            //fin procesamiento
        } // fin de la lìnea
    }
}

void colorReduceMatIt(Mat image, int div)
{
    // div debe ser potencia de 2
    int n= static_cast<int>(log(static_cast<double>(div))/log(2.0) + 0.5);

    //mascara para redondear el valor del pixel
    uchar mask = 0xFF << n; //ejemplo para div=16, mask = 0xF0
    uchar div2 = div >> 1; //div2 = div/2;

    //obtenemos los iteradores
    Mat_<Vec3b>::iterator it = image.begin<Vec3b>();
    Mat_<Vec3b>::iterator itend = image.end<Vec3b>();


    for ( ; it!=itend; ++it)
    {
        // procesamos cada pixel
        (*it)[0] &= mask;
        (*it)[0] += div2;
        (*it)[1] &= mask;
        (*it)[1] += div2;
        (*it)[2] &= mask;
        (*it)[2] += div2;
        //fin
    }
}

void colorReduceItVec3b(Mat image, int div)
{
    MatIterator_<Vec3b> it = image.begin<Vec3b>();
    MatIterator_<Vec3b> itend = image.end<Vec3b>();

    const Vec3b offset(div/2, div/2, div/2);

    for ( ; it != itend; ++it) {
        //procesamos cada pixel
        *it = *it/div*div + offset;
    }
}
