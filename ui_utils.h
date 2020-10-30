#ifndef UI_UTILS_H
#define UI_UTILS_H

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <QLabel>

//参数1-显示图像的Label，参数2-要显示的Mat
void LabelDisplayMat(QLabel *label,const cv::Mat &mat);

#endif // UI_UTILS_H
