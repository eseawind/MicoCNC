#include "error.h"

typedef struct {
    float targetX, targetY;
    int feedSpeed;
    int toolType;
    int spindleSpeed;
    int GCommand;
} CommandData;

typedef struct {
    float currentX, currentY;
    float targetX, targetY;
    int feedSpeed;
    int toolType;
    int spindleSpeed;
    int GCommand;
} currentData;

void init(void);
void processCommand(void);

char * getCommand(void);
CommandData splitCommand(char * commandString);
void setParameters(CommandData command);
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

