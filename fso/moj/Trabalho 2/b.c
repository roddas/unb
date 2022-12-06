#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigalarm_counter = 0;
void sigusr_handler (int);
void sigalarm_handler (int);

int main (int argc, char **argv)
{
	struct sigaction sa_sigusr;
	memset(&sa_sigusr,0, sizeof(sa_sigusr));
	sa_sigusr.sa_handler = sigusr_handler;
	
	struct sigaction sa_sigalarm;
	memset(&sa_sigalarm,0, sizeof(sa_sigalarm));
	sa_sigalarm.sa_handler = sigalarm_handler;
	
	while(1){
		
		sigaction(SIGUSR1,&sa_sigusr,NULL);
		sigaction(SIGALRM,&sa_sigalarm,NULL);
	}
	
	return EXIT_SUCCESS;
}
void sigusr_handler (int signal_number)
{
	puts("SIGUSR1 eh para aproveitar mais um pouco");
}
void sigalarm_handler (int signal_number)
{
	if(++sigalarm_counter == 3){
		puts("Os incomodados que se mudem, tchau");
		exit(EXIT_SUCCESS);
	}
	puts("Ai que sono, quero dormir mais um pouco");
}
