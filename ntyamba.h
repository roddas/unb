/*
 *Hello, dear programmer, I'm Rodolfo Cabral, programmer from Angola, Luanda
 *I created this library for study purposes, feel free if you want to increase it ,adding new contents
 * Contacts
 * https://github.com/roddas
 * 
 * First of all, you've to include the following libraries if yo want to use :
 * stdio,stdlib,ctype and string
 * */
 
#ifndef NTYAMBA_H
#define NTYAMBA_H

/* Prototype of functions */

/* Miscelanea functions */
void addChar(char *,char); // Put a single character at end of string 
void printArray(const void *,size_t,size_t); // Print an array, no matter the type

/* Sorting functions and the set */
void sort_array(void *,size_t ,size_t,int); // Using Quick Sort, flag 0 to decreasing and other else to increasing
int increasing_int(const void *,const void *);
int decreasing_int(const void *,const void *);
int increasing_char(const void *,const void *);
int decreasing_char(const void *,const void *);
int increasing_double(const void *,const void *); //Only for double type array 
int decreasing_double(const void *,const void *);
void leftRotation(void *,int);
int prime(int);
int number_digits(size_t); // Return the number os digits in a number
int *split_number(size_t); // Break the digits and return each of them in an array

/* Bodies of functions */
void addChar(char *string,char ch)
{
	char tmp[1] = {0};
	tmp[0] = ch;
	strcat(string,tmp);
}

void printArray(const void *arr,size_t length,size_t bytes)
{
	size_t counter = 0;
	if(bytes == sizeof(int))
	{
		int *array = (int*)arr;
		for(counter = 0; counter < length;counter++)
			printf("%d ",array[counter]);
	}else if(bytes == sizeof(double))
	{
		double *array = (double*)arr;
		for(counter = 0; counter < length;counter++)
			printf("%.3lf ",array[counter]);
	}else if(bytes == sizeof(char))
	{
		char *array = (char*)arr;
		for(counter = 0; counter < length;counter++)
			printf("%c",array[counter]);
	}
	printf("\n");
}
int increasing_int(const void *a,const void *b)
{
	return (*(int *)a) - (*(int *)b);
}
int decreasing_int(const void *a,const void *b)
{
	return (int)(*(int *)b) - (int)(*(int *)a);
}
int increasing_double(const void *a,const void *b)
{
	return (*(double *)a) - (*(double *)b);
}
int decreasing_double(const void *a,const void *b)
{
	return (*(double *)b) - (*(double *)a);
}
int increasing_char(const void *a,const void *b)
{
	return (*(char *)a) - (*(char *)b);
}
int decreasing_char(const void *a,const void *b)
{
	return (*(char *)b) - (*(char *)a);
}
void sort_array(void *array,size_t length,size_t bytes,int flag)
{
	if(bytes == sizeof(double))
		if(flag)
			qsort(array,length,bytes,increasing_double);
		else
			qsort(array,length,bytes,decreasing_double);
			
	else if(bytes == sizeof(int))
		if(flag)
			qsort(array,length,bytes,increasing_int);
		else
			qsort(array,length,bytes,decreasing_int);
	
	else
		if(flag)
			qsort(array,length,bytes,increasing_char);
		else
			qsort(array,length,bytes,decreasing_char);	
}
void leftRotation(void *arr,int length)
{
	if(sizeof(&arr) == sizeof(char))
	{
		char *array  = (char *)array;
		int a;
		char *tmp = (char *)calloc(length,sizeof(char));
		tmp[0] = array[length-2];
		
		for(a = 0;a < length-2;a++)
		{
			tmp[a+1] = array[a];
		}
		
		strcpy(array,tmp);
		free(tmp);
		puts(array);
	}
}
int prime(int n)
{
	int ret = 2;
	for(int a = 2; a < n; a++)
	{
		if(n%a == 0)
			ret++;
		if(ret > 2)
			break;
	}
	return !(ret > 2);
}
int number_digits(size_t number)
{
	int ret = 1;
	while(number/=10)
		ret++;
	return ret;
}
int *split_number(size_t number)
{
	int q = number_digits(number);
	int *array = (int *)calloc(q,sizeof(int));
	int size = 0;
	while(number > 0)
	{
		int digit = number%10;
		array[q - (++size)] = digit;
		number /= 10;
	}
	return array;
}

#endif
