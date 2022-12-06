#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char **argv){
	
	printf("The main program process ID is: %d\n",(int)getpid());
	pid_t child = fork();
	if(child != 0 ){
		printf("This is the parent process, with ID: %d\n",(int)getpid());
		printf("The child's process ID: %d\n",child);
	}else{
		printf("This is the child process , with ID: %d\n",(int)getpid());
	}
	return EXIT_SUCCESS;
}
