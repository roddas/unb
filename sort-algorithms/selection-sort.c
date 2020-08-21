#include<stdio.h>
#include<stdlib.h>

#define lu size_t
#define type int
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A)<= (B))
#define swap(A,B) { type tmp = B; B = A; A = tmp; }
#define compare_swap(A,B){ if(less(A,B)) swap(A,B); }

void selection_sort(type *,lu ,lu );
void print_array(type *,lu ,lu );

int main(void)
{
	type array[] = {12,324,5,7,-2,5,6,8};
	
	print_array(array,0,8);
	selection_sort(array,0,8);
	print_array(array,0,8);
	
	return EXIT_SUCCESS;
}
void selection_sort(type *array,lu left,lu right)
{
	for(lu i = left;i <= right;i++)
	{
		int minor = i; 
		for(int j = i+1; j <= right;j++)
			if(less(array[j],array[minor]))
				minor = j;
		compare_swap(array[minor],array[i]);
	}
}
void print_array(type *array,lu left,lu right)
{
	for(lu a = left; a < right;a++)
		printf("%d%s",array[a],(a+1 == right ? "\n" : " "));
}
