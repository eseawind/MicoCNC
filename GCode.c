#include "GCode.h"

int  main(void){
    init();
    while(1){
        processCommand();
    }
    return 0;
}

void processCommand(void){
    static CommandData command;
    command = splitCommand(getCommand());
    setParameters(command);
    if (ready()){
        run();
    }
}
//从串口中获取一条命令
char * getCommand(void){
    
}

//拆分命令
CommandData splitCommand(char * commandString){
    
}

//根据拆分后的命令设置参数
void setParameters(CommandData command){
    setFeedSpeed(command.feedSpeed);
    setSpindleSpeed(command.spindleSpeed);
    setToolType(command.toolType);
    setGCommand(command.GCommand);
    setLine(command.targetX, command.targetY);
}

//各参数是否设置无误
bool ready(void){
    int i;
    for (i = 0; i < ERROR; i++ ){
        if (errorData[i].isError){
           errorData[ERROR].isError = 1;
           // TODO: 将errorMsg追加到allError.errorMsg中去
        }
    }
    if (errorData[ERROR].isError){
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
