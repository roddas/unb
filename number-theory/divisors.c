#include<stdio.h>
#include<stdlib.h>

int divisors(int);

int main(void){
	printf("%d\n",divisors(10));
	return EXIT_SUCCESS;
}

int divisors(int number){
	int ret = 2;
	int i = 2;
	
	while((i*i) < number){
		if(number%i == 0)
			ret += 2;
		++i;
	}
	if((i*i) == number)
		++ret;
	return ret;
}
