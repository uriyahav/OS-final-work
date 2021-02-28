#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc , char** argv){
	//accept argument from termianl - evrey argument is accepted as a string, so we convert the string to int
	//server pid
    pid_t pid = atoi(argv[1]);
    //signal number
    int signalNum = atoi(argv[2]);
    //count of signal
    int countSignal = atoi(argv[3]);

    for (int i = 0; i < countSignal; i++)
    {
        kill(pid, signalNum);
    }
}