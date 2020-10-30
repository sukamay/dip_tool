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

#endif // STRUCT_DEFINE_H
