#ifndef GCode_H_
#define GCode_H_
#include "error.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    float targetX, targetY;
    int feedSpeed;
    int toolType;
    int spindleSpeed;
    int GCommand;
} CommandData;
CommandData commandData;

typedef struct {
    float currentX, currentY;
    float targetX, targetY;
    int feedSpeed;
    int toolType;
    int spindleSpeed;
    int GCommand;
} CurrentData;

void init(void);
void processCommand(void);

char * getCommand(void);
void splitCommand(char * commandString);
void setParameters(void);
bool ready(void);
void run(void);

void setLine(float targetX, float targetY);
void setFeedSpeed(int feedSpeed);
void setSpindleSpeed(int spindleSpeed);
void setToolType(int toolType);
void setGCommand(int GCommand);

void spindleRun(void);
void toolRun(void);
void feedRun(void);

#endif /* GCode_H_ */
