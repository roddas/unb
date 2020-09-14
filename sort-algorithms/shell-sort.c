#include<stdio.h>
#include<stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A)<= (B))
#define swap(A,B) { int tmp = B; B = A; A = tmp; }
#define compare_swap(A,B){ if(less(A,B)) swap(A,B); }

void insertion_sort_h(int *,int ,int ,int);
void print_array(int *,int ,int );
void shell_sort(int *,int ,int);

int main(void)
{
	int array[] = {12,324,5,7,-2,5,6,8};
	int left = 0,right = 8;
	
	print_array(array,left,right);
	shell_sort(array,left,right);
	print_array(array,0,8);
	
	return EXIT_SUCCESS;
}
void insertion_sort_h(int *array,int left ,int right,int h)
{
	for(int i = left + h; i <= right;i++)
	{
		int j = i;
		int tmp = array[i];
		
		while(j >= left+h && less(tmp,array[j-h]))
		{
			array[j] = array[j-h];
			j -= h;
		}
		array[j] = tmp;
	}
}
void shell_sort(int *array,int left ,int right)
{
	int h;
	for(h = 1; h <= (right - left) - 2; h = 3 * h + 1);
	for(;h > 0;h /= 3)
		insertion_sort_h(array,left,right,h);
}
void print_array(int *array,int left,int right)
{
	for(int a = left; a < right;a++)
		printf("%d%s",array[a],(a+1 == right ? "\n" : " "));
}
