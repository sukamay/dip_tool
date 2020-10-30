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
    int channels = 0;
    int hist_size = 256;
    float h_range[2] = {0, 255};
    const float *ranges[1] = {h_range};
    calcHist(&input_mat, 1, &channels, Mat(), output_mat, 1, &hist_size, ranges);
    return OK;
}

ERROR_CODE GaussianFilter(const Mat &input_mat, Mat &output_mat, GaussianFilterParams &params) {
    if (input_mat.empty()) {
        return INPUT_INVALID;
    }
    if (!(params.kernel_x > 0 && params.kernel_x%2 == 1 && params.kernel_y > 0 && params.kernel_y%2 == 1)) {
        return PARAM_INVALID;
    }
    GaussianBlur(input_mat, output_mat, Size(params.kernel_x, params.kernel_y), params.sigma);
    return OK;
}

ERROR_CODE MeanFilter(const Mat &input_mat, Mat &output_mat, MeanFilterParams &params) {
    if (input_mat.empty()) {
        return INPUT_INVALID;
    }
    if (!(params.kernel_x > 0 && params.kernel_x%2 == 1 && params.kernel_y > 0 && params.kernel_y%2 == 1)) {
        return PARAM_INVALID;
    }
    blur(input_mat, output_mat, Size(params.kernel_x, params.kernel_y));
    return OK;
}

ERROR_CODE MedianFilter(const Mat &input_mat, Mat &output_mat, MedianFilterParams &params) {
    if (input_mat.empty()) {
        return INPUT_INVALID;
    }
    if (!(params.kernel_size > 0 && params.kernel_size%2 == 1)) {
        return PARAM_INVALID;
    }
    medianBlur(input_mat, output_mat, params.kernel_size);
    return OK;
}

ERROR_CODE BilateralFilter(const Mat &input_mat, Mat &output_mat, BilateralFilterParams &params) {
    if (input_mat.empty()) {
        return INPUT_INVALID;
    }
    bilateralFilter(input_mat, output_mat, params.diameter, params.sigma_color, params.sigma_space);
    return OK;
}
