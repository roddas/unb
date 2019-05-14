#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int a,b;
	while(	scanf("%d %d",&a,&b),b!= -1 && a!=-1)
	{
		printf("\n%d %d\n",a,b);
	}
		
	{return EXIT_SUCCESS;}
}
