#include <stdio.h>
#include <signal.h>
#include <unistd.h>
static int count = 0;
void my_signal_handler(int sigNum){
    if(sigNum == SIGINT){
        count++;
    }

    else if(sigNum == SIGUSR1){
        printf("Number of SIGINT = %d \n", count);
    }
}

int main(){
pid_t pid = getpid();
printf("the pid is = %d\n", pid);

while(1){
    //connect the signals to the handler
    signal(SIGUSR1, my_signal_handler);
    signal(SIGINT, my_signal_handler);
}
return 0;
}
