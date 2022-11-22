#include<stdio.h>
#include<stdlib.h>

#define Key(A) (A)
#define less(A,B) ( Key(A) < Key(B) )
#define lesseq(A,B) ( Key(A) <= Key(B) )
#define exch(A,B) { int t = A; A = B; B = t; }
#define cmpexch(A,B) { if(less(B,A)) exch(A,B); }

void quicksort(int *,int,int);
void print_array(int *,int,int);
int separa(int *,int,int);

int main(void)
{
	int array[] = {9,8,7,4,3,2,-1,5};
	int l = 0, r = 7;
	print_array(array,l,r);
	quicksort(array,l,r);
	print_array(array,l,r);
	return EXIT_SUCCESS;
}
void print_array(int *array,int left,int right)
{
	for(int a = left; a <= right;a++)
		printf("%d%s",array[a],(a+1 > right ? "\n" : " "));
}
int separa(int *v,int l,int r)
{
	int i = l-1,j = r;
	int c = v[r];
	for(;;)
	{
		while(less(v[++i],c));
		while(less(c,v[--j]))
			if(j == l)
				break;
		if(i >= j)
			break;
		exch(v[i],v[j]);
	}
	exch(v[i],v[r]);
	return i;
}
void quicksort(int *v,int l,int r)
{
	int j;
	if( l >= r)
		return;
		
	j = separa(v,l,r);
	quicksort(v,l,j-1);
	quicksort(v,j+1,r);
}
