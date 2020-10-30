#include "image.h"

using namespace cv;

Image::Image() {

}

Image::Image(string file_name) {
    img = imread(file_name);
}

ERROR_CODE Image::SetImg(string file_name) {
    img = imread(file_name);
    if (img.empty()) {
        return IMG_LOAD_FAILED;
    }
    return OK;
}

ERROR_CODE Image::SetImg(Mat &mat) {
    mat.copyTo(img);
    return OK;
}

ERROR_CODE Image::Dilate(Mat &output_mat, DilateParams &params) {
    if (img.empty()) {
        return INPUT_INVALID;
    }
    Mat kernel = getStructuringElement(params.morph_shape, Size(params.kernel_size, params.kernel_size));
    dilate(img, output_mat, kernel);
    return OK;
}

ERROR_CODE Image::Erode(Mat &output_mat, ErodeParams &params) {
    if (img.empty()) {
        return INPUT_INVALID;
    }
    Mat kernel = getStructuringElement(params.morph_shape, Size(params.kernel_size, params.kernel_size));
    erode(img, output_mat, kernel);
    return OK;
}
