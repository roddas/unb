#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char **argv){
	
	int counter = 1024*4;
	while(1){
		if(fork() != 0 ){
			printf("Child process created, lets fill the RAM and get  the CPU busy :-D \n");
			int *ptr = (int*)calloc(counter,sizeof(int));
			counter += 1024;
		}else{
			printf("This is the child process , with ID: %d\n",(int)getpid());
		}
	}
	return EXIT_SUCCESS;
}
