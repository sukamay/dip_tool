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

ERROR_CODE LoadImg(string file_name, Mat &mat);

ERROR_CODE Dilate(const Mat &input_mat, Mat &output_mat, DilateParams &params);
ERROR_CODE Erode(const Mat &input_mat, Mat &output_mat, ErodeParams &params);

ERROR_CODE GetHist(const Mat &input_mat, Mat &output_mat);

ERROR_CODE GaussianFilter(const Mat &input_mat, Mat &output_mat, GaussianFilterParams &params);
ERROR_CODE MeanFilter(const Mat &input_mat, Mat &output_mat, MeanFilterParams &params);
ERROR_CODE MedianFilter(const Mat &input_mat, Mat &output_mat, MedianFilterParams &params);
ERROR_CODE BilateralFilter(const Mat &input_mat, Mat &output_mat, BilateralFilterParams &params);


#endif // IMAGE_H
