#include<stdio.h>
#include<stdlib.h>

#define Key(A) (A)
#define less(A,B) ( Key(A) < Key(B) )
#define lesseq(A,B) ( Key(A) <= Key(B) )
#define exch(A,B) { int t = A; A = B; B = t; }
#define cmpexch(A,B) { if(less(B,A)) exch(A,B); }

void quicksort(int *,int,int);
void print_array(int *,int,int);
void merge(int *,int,int,int);
void merge_sort(int *,int,int);

int main(void)
{
	int array[] = {9,8,7,4,3,2,-1,5};
	int l = 0, r = 7;
	print_array(array,l,r);
	merge_sort(array,l,r);
	print_array(array,l,r);
	
	return EXIT_SUCCESS;
}
void print_array(int *array,int left,int right)
{
	for(int a = left; a <= right;a++)
		printf("%d%s",array[a],(a+1 > right ? "\n" : " "));
}
void merge(int *v,int l,int r1,int r2)
{
	int *v2 = (int *)malloc((r2-l+1) * sizeof(int));
	int k = 0, i = l,j = r1 + 1;
	
	while( i <= r1 && j <= r2)
		v2[k++] = (less(v[i],v[j])) ? v[i++]:v[j++];
	
	while(i <= r1)
		v2[k++] = v[i++];
	
	while(j <= r2)
		v2[k++] = v[j++];
	
	k = 0;
	for(i = l; i <= r2;i++)
		v[i] = v2[k++];
	
	free(v2);
}
void merge_sort(int *v,int l,int r)
{
	if(l >= r)
		return;
	int meio = (l+r)/2;
	merge_sort(v,l,meio);
	merge_sort(v,meio+1,r);
	merge(v,l,meio,r);
}
