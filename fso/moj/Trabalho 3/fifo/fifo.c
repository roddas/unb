#include<stdio.h>
#include<stdlib.h>

#define li long int
#define INIT -1

li * init_queue(li);
short int is_full(li);
int search(li *,li,li );

int main(void){
	
	li quantidade_quadros,quantidade_paginas;
	
	scanf("%ld%ld",&quantidade_quadros,&quantidade_paginas);
	
	li *quadros = init_queue(quantidade_quadros);
	li page_faults = 0;
	
	for(li i = 0; i < quantidade_paginas; i++)
	{
		li pagina;
		scanf("%ld",&pagina);
		
		if(search(quadros,quantidade_quadros, pagina) == INIT)
		{
			page_faults++;
			quadros[page_faults%quantidade_quadros] = pagina;
		}
	}
	printf("%ld\n",page_faults);
	free(quadros);
	return EXIT_SUCCESS;
}

int search(li *queue,li size,li value){
	for(li a = 0; a < size ;a++)
		if(queue[a] == value)
			return 1;
	return INIT;
}

li *init_queue(li size){
	li *ptr = malloc(size*sizeof(li));
	for(li a = 0; a < size;a++)
		ptr[a] = INIT;
	return ptr;
}
