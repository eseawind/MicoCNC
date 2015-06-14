#ifndef ERROR_H_
#define ERROR_H_

#include "bool.h"
#define ERROR 6

typedef struct {
    bool isError;
    char * errorMsg;
} Error;

Error targetXError = {.errorMsg = "target X is error\n"};
Error targetYError = {.errorMsg = "target Y is error\n"};
Error feedSpeedError = {.errorMsg = "feedSpeed is error\n"};
Error spindleSpeedError = {.errorMsg = "spindleSpeed is error\n"};
Error toolTypeError = {.errorMsg = "toolType is error\n"};
Error GCodeError = {.errorMsg = "GCode is error\n"};
Error allError;

Error * errorData[ERROR + 1];

errorData[0] = &targetXError;
errorData[1] = &targetYError;
errorData[2] = &feedSpeedError;
errorData[3] = &spindleSpeedError;
errorData[4] = &toolTypeError;
errorData[5] = &GCodeError;
errorData[6] = &allError; 
#endif /* ERROR_H_ */
