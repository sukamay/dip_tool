#ifndef STRUCT_DEFINE_H
#define STRUCT_DEFINE_H

struct DilateParams {
    int iteration;
    int kernel_size;
    int morph_shape;
};

struct ErodeParams {
    int iteration;
    int kernel_size;
    int morph_shape;
};

struct GaussianFilterParams {
    int kernel_x;
    int kernel_y;
    double sigma;
};

struct MeanFilterParams {
    int kernel_x;
    int kernel_y;
};

struct MedianFilterParams {
    int kernel_size;
    double sigma;
};

struct BilateralFilterParams {
    int diameter;
    double sigma_color;
    double sigma_space;
};

#endif // STRUCT_DEFINE_H
