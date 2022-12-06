#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct {
	int size;
	int *vector;
}array;

void *sort(void *);
int cmp(const void *, const void *);
short int compare_vectors(int *,int *, int);
void print_array(array );

int main(int argc, char **argv){
	int quantidade;
	scanf("%d",&quantidade);
	
	pthread_t t1,t2;
	array first,second;
	
	first.size = second.size = quantidade;	
	first.vector = malloc(quantidade * sizeof(int));
	second.vector = malloc(quantidade * sizeof(int));
	
	for(int a = 0; a < quantidade;a++){
		scanf("%d",&first.vector[a]);
	}
	for(int a = 0; a < quantidade;a++){
		scanf("%d",&second.vector[a]);
	}
	
	pthread_create(&t1,NULL,sort,&first);
	pthread_create(&t2,NULL,sort,&second);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
		
	printf( compare_vectors(first.vector,second.vector,quantidade) ? "Mesmos elementos\n": "Diferentes\n");
	
	free(first.vector);
	free(second.vector);
	return EXIT_SUCCESS;
}
void print_array(array arr){
	for(int a = 0; a < arr.size;a++)
		printf("%d ",arr.vector[a]);
	printf("\n");
}

void *sort(void *data){
	array * arr = (array *)data;
	qsort(arr->vector,arr->size,sizeof(int),cmp);
	return NULL;
}

short int compare_vectors(int *first_vector,int *second_vector, int size){
	for(int a = 0; a < size;a++){
		if(first_vector[a] != second_vector[a])
			return 0;
	}
	return 1;
}

int cmp(const void *first, const void *second){
	return *(int *)first - *(int *)second; 
}
