#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc , char** argv){
	//get the argument read him from termianl 
	//evrey argument is accepted as a string, so we convert the string to int
	pid_t pid = atoi(argv[1]);

	/*
	kill sends a signal to a process.
	you caan send also to group of process.
	if kill return 0 so the process with the given pid does exist.
	else if we get ESRCH/ EPERM error - the process with the given pidcdoes not exist 
	*/
	if( kill(pid, 0) == 0){
		printf("Process %d exists\n", pid);
	}	
	else{
		if(errno==ESRCH) printf("Process %d does not exist\n", pid);
		if(errno==EPERM) printf("Process %d exists but we have no permission\n", pid);
	}
}
