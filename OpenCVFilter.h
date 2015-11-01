#ifndef OPENCVFILTER_H
#define OPENCVFILTER_H


#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "Mat2QImage.h"

using namespace cv;
using namespace std;

class CV_Filters
{
/*
    void CannyThreshold(Mat &src, int lowThreas,int kernel_Size_Noise, int kernel_Size_Canny)
    {
      int ratio = 3;

      Mat intern_buffer;

      /// Reduce noise with a kernel 3x3
      blur( &src,intern_buffer, Size(kernel_Size_Noise,kernel_Size_Noise) );

      /// Canny detector
      Canny( intern_buffer, intern_buffer, lowThreas, lowThreas*ratio, kernel_Size_Canny);

      /// Using Canny's output as a mask, we display our result
      dst = Scalar::all(0);
      //dst =  Scalar::all(255) - detected_edges;
      //src.copyTo( buffer, intern_buffer);
      src.copyTo( dst, intern_buffer);
    }

*/
};



#endif // OPENCVFILTER_H
