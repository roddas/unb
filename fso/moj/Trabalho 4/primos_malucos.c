#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<pthread.h>

typedef struct{
	int result;
}param;

void *primo_maluco(void *);

int main(void){
	
	int q;
	scanf("%d",&q);
	
	if(q %2 != 0)
	{
		param parametro;
	
		scanf("%d",&parametro.result);
		printf("%d\n",(int)primo_maluco(&parametro));
		--q;
	}
	while(q > 0)
	{
		param parametro1,parametro2;
		pthread_t t1,t2;
		void *r1, *r2;
		
		scanf("%d",&parametro1.result);
		scanf("%d",&parametro2.result);
		q -= 2;
		
		pthread_create(&t1,NULL,primo_maluco,&parametro1);
		pthread_create(&t2,NULL,primo_maluco,&parametro2);
		
		pthread_join(t1,&r1);
		pthread_join(t2,&r2);
		
		printf("%d\n%d\n",(int)r1,(int)r2);
		
	}
	return EXIT_SUCCESS;
}

void *primo_maluco(void *parameter){
	
	param *tmp = parameter;
	int number = tmp->result;
	
	if (number <= 508079)
    {
        return (void *)508079;
    }
    else
    {
		while(number++)
		{
			int index = 0;
			int root = floor(sqrt(number));
			if(number%2 != 0 && number%3 != 0 && number%5 != 0 && number%7 != 0)
			{
				for(int a = 11; a < root; a += 2)
				{
					if(number %a == 0)
						index++;
					if(index > 10)
					{
						return (void *)number;
					}
				}
			}
		}
	}
	return NULL;
}
