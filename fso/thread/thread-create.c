#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *print_xs(void *);

int main(int argc, char **argv){
	
	pthread_t thread_id;
	
	/* Created a new thread. The new thread will run the print_xs function */
	pthread_create(&thread_id, NULL, &print_xs,NULL);
	printf("The main flow execution");
	
	return EXIT_SUCCESS;
}

void *print_xs(void *unused){
	printf("\nThe funcion thread execution\n");
	return NULL;
}
