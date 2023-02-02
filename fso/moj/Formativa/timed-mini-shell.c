#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<string.h>
#include<errno.h>

typedef struct timeval timeval;

double time_diff(timeval *,timeval *);

int main(int argc, char **argv)
{
	char program[256],arg[256];
	double sum_time = 0;
	timeval start,end;
	int ret;
	
	while(scanf("%s %s",program,arg) != EOF)
	{	
		gettimeofday(&start,NULL);
		
		if(fork())
		{
			wait(&ret);
			gettimeofday(&end,NULL);
			double local_time = time_diff(&start,&end);
			sum_time += local_time;
			printf("> Demorou %.1lf segundos, retornou %d\n",local_time,WEXITSTATUS(ret));
			fflush(stdout);
		}
		else
		{
			if(execl(program,program, arg,NULL) == -1)
			{
				printf("> Erro: %s\n", strerror(errno));
				fflush(stdout);
				_exit(errno);
			}
		}
	}
	printf(">> O tempo total foi de %.1lf segundos\n",sum_time);

	return EXIT_SUCCESS;
}

double time_diff(timeval *start,timeval *end)
{
	return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

