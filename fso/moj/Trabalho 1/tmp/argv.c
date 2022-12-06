#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	if(argc == 1){
		printf("0\n");
		return 0;
	}
	printf("%d\n",argc-1);
	for(int a = 1; a < argc;a++){
		printf("%s\n",argv[a]);
	}
	return EXIT_SUCCESS;
}
