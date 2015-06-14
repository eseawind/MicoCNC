#include "GCode.h"

int  main(void){
    init();
    while(1){
        processCommand();
    }
    return 0;
}

void processCommand(void){
    splitCommand(getCommand());
    setParameters();
    if (ready()){
        run();
    }
}
//从串口中获取一条命令
char * getCommand(void){
    
}

//拆分命令
void splitCommand(char * commandString){
    char * pch;
    char commandChar;
    float value;

    pch = strtok(commandString, " ");
    while (pch != NULL){
        commandChar = pch[0];
        value = atof(pch + 1);
        switch (commandChar){
            case 'G':
               commandData.GCommand = (int)value; 
                break;
            case 'S':
               commandData.spindleSpeed = (int)value; 
                break;
            case 'T':
               commandData.toolType = (int)value; 
                break;
            case 'X':
               commandData.targetX = value; 
                break;
            case 'Y':
               commandData.targetY = value; 
                break;
            case 'F':
               commandData.feedSpeed = (int)value; 
                break;
            default:
                break;
        }
        pch = strtok(NULL, " ");
    }
}

//根据拆分后的命令设置参数
void setParameters(){
    setFeedSpeed(commandData.feedSpeed);
    setSpindleSpeed(commandData.spindleSpeed);
    setToolType(commandData.toolType);
    setGCommand(commandData.GCommand);
    setLine(commandData.targetX, commandData.targetY);
}

//各参数是否设置无误
bool ready(void){
    int i;
    for (i = 0; i < ERROR; i++ ){
        if ((*errorData[i]).isError){
           (*errorData[ERROR]).isError = 1;
           // TODO: 将errorMsg追加到allError.errorMsg中去
        }
    }
    if ((*errorData[ERROR]).isError){
        return FALSE;
    }
    return TRUE;
}

//开始执行命令
void run(void){
    spindleRun();
    toolRun();
    feedRun();
}
