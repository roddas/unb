#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int spawn(char *, char **);

int main(int argc, char **argv){
	
	/* The argument list to pass the 'ls' command */
	char *arg_list[] = {
		"ls",
		"-l",
		"/",
		NULL
	};
	/* Spawn a child process running the "ls" command. Ignore the returned child process ID */
	spawn("ls",arg_list);
	printf("It's done\n");
	return EXIT_SUCCESS;
}

int spawn(char *program, char ** arg_list){
	
	/* Duplicate the process */
	pid_t child = fork();
	if(child != 0){
		
		/* This is the parent process */
		return child;
				
	}else{
		/* Now execute the PROGRAM, searching for it in the path */
		execvp(program,arg_list);
		/* Wait for the child process to complete */
		wait(&child);
		if(WIFEXITED(child)){
			printf("The child process exited normally, with exit code %d\n",WEXITSTATUS(child));
		}else{
			printf("The child process exited abnormally\n");
		}
		/*The execvp function return only if an error occurs*/
		fprintf(stderr,"An error occurred in execvp\n");
		abort();
	}
}
