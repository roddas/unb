#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Key(A) (A)
#define less(A,B) ( Key(A) < Key(B) )
#define lesseq(A,B) ( Key(A) <= Key(B) )
#define exch(A,B) { int t = A; A = B; B = t; }
#define cmpexch(A,B) { if(less(B,A)) exch(A,B); }

void quicksort(int *,int,int,int);
void print_array(int *,int,int);
int separa(int *,int,int);
void merge(int *,int,int,int);
void merge_sort(int *,int,int);
void intro_sort(int *,int ,int );
void insertion_sort(int *,int,int);

int quicktrapstop = 0;

int main(void)
{
	int array[] = {9,8,7,12,34,232,-1,5};
	int l = 0, r = 7;
	print_array(array,l,r);
	intro_sort(array,l,r);
	print_array(array,l,r);
	return EXIT_SUCCESS;
}
void intro_sort(int *array,int left,int right)
{
	int max_rec = 2 * log((right-left+1));
	quicksort(array,left,right,max_rec);
	
	if(quicktrapstop)
		merge_sort(array,left,right);
	else
		insertion_sort(array,left,right);
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
void quicksort(int *v,int l,int r,int max_rec)
{
	int j,meio = (l+r)/2;
	if(!max_rec)
	{
		quicktrapstop = 1;
		return;
	}
	if(quicktrapstop)
		return;
	if( l <= 32)
		return;
	exch(v[meio],v[r-1]);
	cmpexch(v[l],v[r-1]);
	cmpexch(v[l],v[r]);
	cmpexch(v[r-1],v[r]);
			
	j = separa(v,l+1,r-1);
	quicksort(v,l,j-1,max_rec-1);
	quicksort(v,j+1,r,max_rec-1);
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
void insertion_sort(int *array,int left,int right)
{
	for(int i = right; i > left;i--)
		cmpexch(array[i-1],array[i]);
		
	for(int i = left + 2;i <= right;i++)
	{
		int j = i;
		int tmp = array[j];
		while(less(tmp,array[j-1]))
		{
			array[j] = array[j-1];
			j--;
		}
		array[j] = tmp;
	}
}
