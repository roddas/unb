#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc, char *argv[]){
	
	void *lib_handle = dlopen(argv[1],RTLD_NOW);
	
	if(lib_handle == NULL)
	{
		puts("nao disponivel");
		return 0;
	}
	
	int (*imprime)(void) = imprime = dlsym(lib_handle,"imprime");
	if(dlerror() != NULL)
	{
		printf("nao implementado\n");
	}else
	{
		int ret = (*imprime)();
		printf("%d\n",ret);
	}

	int (*calcula)(int,int) = dlsym(lib_handle,"calcula");
	if(dlerror() != NULL)
	{
		printf("nao implementado\n");	
	}else
	{
		int calc = (*calcula)(atoi(argv[2]),atoi(argv[3]));
		printf("%d\n",calc);
	}	
	int (*trigo)(double,double*) = dlsym(lib_handle,"trigo");
	if(dlerror() != NULL)
	{
		printf("nao implementado\n");	
	}else
	{
		int trig = (*trigo)(atof(argv[4]),NULL);
		printf("%d\n",trig);
	}
	
	dlclose(lib_handle);
	return 0;
}
