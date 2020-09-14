#include<stdio.h>
#include<stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A)<= (B))
#define swap(A,B) { int tmp = B; B = A; A = tmp; }
#define compare_swap(A,B){ if(less(A,B)) swap(A,B); }

void insertion_sort(int *,int ,int );
void print_array(int *,int ,int );

int main(void)
{
	int array[] = {12,324,5,7,-2,5,6,8};
	
	print_array(array,0,8);
	insertion_sort(array,0,8);
	print_array(array,0,8);
	
	return EXIT_SUCCESS;
}
void insertion_sort(int *array,int left ,int right)
{
   for (int j = left+1; j < right; ++j)
   {
      int x = array[j];
      int i;
      for (i = j-1; i >= left && array[i] > x; --i) 
		array[i+1] = array[i];
      array[i+1] = x;
   }
}
void print_array(int *array,int left,int right)
{
	for(int a = left; a < right;a++)
		printf("%d%s",array[a],(a+1 == right ? "\n" : " "));
}
