#include "image.h"

using namespace cv;

ERROR_CODE LoadImg(string file_name, Mat &mat) {
    mat = imread(file_name);
    if (mat.empty()) {
        return IMG_LOAD_FAILED;
    }
    return OK;
}

ERROR_CODE Dilate(const Mat &input_mat, Mat &output_mat, DilateParams &params) {
    if (input_mat.empty()) {
        return INPUT_INVALID;
    }
    Mat kernel = getStructuringElement(params.morph_shape, Size(params.kernel_size, params.kernel_size));
    dilate(input_mat, output_mat, kernel);
    return OK;
}

ERROR_CODE Erode(const Mat &input_mat, Mat &output_mat, ErodeParams &params) {
    if (input_mat.empty()) {
        return INPUT_INVALID;
    }
    Mat kernel = getStructuringElement(params.morph_shape, Size(params.kernel_size, params.kernel_size));
    erode(input_mat, output_mat, kernel);
    return OK;
}

ERROR_CODE GetHist(const Mat &input_mat, Mat &output_mat) {
    return OK;
}
