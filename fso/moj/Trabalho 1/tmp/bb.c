#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc, char *argv[]){
	
	void *handle = dlopen(argv[1], RTLD_NOW);
	
	if(handle == NULL){
		// a lib não existe
		printf("nao disponivel\n");
		return 0;
		
	}else{
		// A lib Existe
		int (*imprime)(void) = dlsym(handle,"imprime");
		
		if(dlerror() != NULL){ // Existe uma mensagem de erro
			printf("nao implementado\n");	
		}else{
			int resultado = (*imprime)();
			printf("%d\n",resultado);
		}
		
		int (*calcula)(int, int) = dlsym(handle,"calcula");
		if(dlerror() != NULL){
			printf("nao implementado\n");
		}else{
			int resultado = (*calcula)(atoi(argv[2]),atoi(argv[3]));
			printf("%d\n",resultado);
		}
		
		int (*trigo)(double, double*) = dlsym(handle,"trigo");
		
		if(dlerror() != NULL){
			printf("nao implementado\n");
		}else{
			int resultado = (*trigo)(atof(argv[4]),NULL);
			printf("%d\n",resultado);
		}
		dlclose(handle);
	}
	
	return EXIT_SUCCESS;
}
