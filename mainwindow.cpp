#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QPixmap>
#include <QFileDialog>
#include "Mat2QImage.h"
#include "OpenCVFilter.h"


using namespace cv;
using namespace std;


Mat2QImageClass m2i;


Mat src; // Orginal bild
Mat buffer;   //Zwischenspeicher für Manipulation

Mat src_gray; //Graubild
Mat dst;      //Manipuliertes Bild


Mat detected_edges;

VideoCapture cap(0); // open the video camera no. 0
QImage qim1, qimCanny,qimBuffer;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void CannyThreshold(int lowThreas,int kernel_Size_Noise, int kernel_Size_Canny)
{
  int ratio = 3;

  Mat intern_buffer;

  /// Reduce noise with a kernel 3x3
 // blur( buffer,intern_buffer, Size(kernel_Size_Noise,kernel_Size_Noise) );
  blur(buffer,intern_buffer, Size(kernel_Size_Noise,kernel_Size_Noise) );
  /// Canny detector
  Canny( intern_buffer, intern_buffer, lowThreas, lowThreas*ratio, kernel_Size_Canny);

  /// Using Canny's output as a mask, we display our result
  dst = Scalar::all(0);
  //dst =  Scalar::all(255) - detected_edges;
  //src.copyTo( buffer, intern_buffer);
  src.copyTo( dst, intern_buffer);
}




void MainWindow::on_pushButton_clicked()
{


              cap.read(src); // read a new frame from video
              cv::resize(src, src, Size(371, 281), 0, 0, INTER_CUBIC);
              // Darstellen des Captures
              qim1 = m2i.Mat2QImage(src);
              ui->label->setPixmap(QPixmap::fromImage(qim1));
              ui->label->show();

                /// Convert the image to grayscale cv::mat
                cvtColor(src, buffer,CV_BGR2GRAY );

}



void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    CannyThreshold(value,ui->lcdNumber_2->value(),ui->lcdNumber_3->value());
    qimCanny = m2i.Mat2QImage(dst);
    ui->label_2->setPixmap(QPixmap::fromImage(qimCanny));
    ui->label_2->show();
}


