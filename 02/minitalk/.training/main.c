#include <signal.h>
#include <unistd.h>


void	signal_handler(int sig)
{
	char	s1[] = "SIGUSR1\n";
	char	s2[] = "SIGUSR2\n";
	if (sig == SIGUSR1)
        write(1, s1, sizeof(s1));
    else if (sig == SIGUSR2)
        write(1, s2, sizeof(s2));
	signal(sig, signal_handler);
}

int	main()
{
	pid_t	pid;

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	return (0);
}
