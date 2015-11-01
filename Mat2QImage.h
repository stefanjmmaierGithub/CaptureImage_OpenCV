#ifndef MAT2QIMAGE_H
#define MAT2QIMAGE_H

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QPixmap>
#include <QApplication>
#include <QtGui>



class Mat2QImageClass
{

public:

    QImage Mat2QImage(cv::Mat const& src)
    {
        cv::Mat temp; // make the same cv::Mat
        cvtColor(src, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
        QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
        dest.bits(); // enforce deep copy, see documentation
        // of QImage::QImage ( const uchar * data, int width, int height, Format format )
        return dest;
    }

    QImage GrayMat2QImage(cv::Mat const& src)
    {
        cv::Mat temp; // make the same cv::Mat
        /// Makes a copy
        src.copyTo(temp);
        QImage dest((const uchar *) src.data, src.cols, src.rows, src.step, QImage::Format_RGB888);
        dest.bits(); // enforce deep copy, see documentation
        // of QImage::QImage ( const uchar * data, int width, int height, Format format )
        return dest;
    }


    cv::Mat QImage2Mat(QImage const& src)
    {
        cv::Mat tmp(src.height(),src.width(),CV_8UC3,(uchar*)src.bits(),src.bytesPerLine());
        cv::Mat result; // deep copy just in case (my lack of knowledge with open cv)
        cvtColor(tmp, result,CV_BGR2RGB);
        return result;
    }

};


#endif // MAT2QIMAGE_H
