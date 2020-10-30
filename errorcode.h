#ifndef ERRORCODE_H
#define ERRORCODE_H

enum ERROR_CODE {
    OK              = 0,
//    load img:1000001~1000010
    IMG_LOAD_FAILED = 1000001,
//    img morphology:1000011~1000031
    INPUT_INVALID   = 1000011,
    PARAM_INVALID   = 1000012,

};

#endif // ERRORCODE_H
