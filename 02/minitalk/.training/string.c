// C program to implement sighup(), sigint()
// and sigquit() signal functions
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
  
void sigusr1()
{
    signal(SIGHUP, sighup); /* reset signal */
    printf("CHILD: I have received a SIGHUP\n");
}

void sigusr2()
{
    printf("My DADDY has Killed me!!!\n");
    exit(0);
}

int main(int argc, char **argv)
{
	int pid = fork();

	if (argc == 3)
	{
		if (pid < 0) 
		{
			perror("fork");
			exit(1);
		}
		if (pid == 0)
		{
			printf("child\n");
			signal(SIGUSR1, sigusr1);
			while(1);
		}
		else
		{
			printf("parent\n");
			printf("%d\n", pid);
			signal(SIGUSR2, sigusr2);
			//kill(pid, SIGUSR1);
		}	
	}
	return 0;
}
