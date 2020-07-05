#include<stdio.h>
#include<stdlib.h>

#define lu size_t

void bubble_sort(int *,lu);
void swap(int *,int *);
void print_array(int *,lu);

int main(void)
{
	int vector[] = {1,23,0,-2,434,5,66,7765,56,55,56,345,345,34532454,24};
	lu size = 15;
	printf("Original array : ");
	print_array(vector,size);
	bubble_sort(vector,size);
	printf("Array after sorted using Bubble Sort : ");
	print_array(vector,size);
	return EXIT_SUCCESS;
}
void bubble_sort(int *vector,lu size)
{
	for(lu i = 0; i < size;i++)
	{
		for(lu j = i+1; j < size;j++)
		{
			if(vector[i] > vector[j])
				swap(&vector[i],&vector[j]);
		}
	}
}
void swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void print_array(int *vector,lu size)
{
	for(lu a = 0 ; a < size;a++)
		printf("%d%s",vector[a],(a+1 == size ? "\n" : " "));
}
