#ifndef IMAGE_H
#define IMAGE_H

#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "errorcode.h"
#include "struct_define.h"

using std::string;
using namespace cv;

class Image
{
public:
    Image();
    Image(string file_name);
    inline const Mat& GetImg() { return img; }
    ERROR_CODE SetImg(string file_name);
    ERROR_CODE SetImg(Mat &mat);
    ERROR_CODE Dilate(Mat &output_mat, DilateParams &params);
    ERROR_CODE Erode(Mat &output_mat, ErodeParams &params);

private:
    Mat img;
};

#endif // IMAGE_H
