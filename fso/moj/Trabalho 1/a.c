#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	if(argc == 1){
		puts("0");
	}else{
		printf("%d\n",argc-1);
		for(int a = 1; a <= argc -1;a++){
			puts(argv[a]);
		}
	}
	return EXIT_SUCCESS;
}
