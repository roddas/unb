#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv){
	
	printf("The process ID is %d\n",(int)getpid());
	printf("The parent process ID is %d\n",(int)getppid());
	
	return EXIT_SUCCESS;
}
