#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int	main(int argc, char *argv[])
{
	if (argc < 3)
		printf("Usage : %s PID \n", argv[0]);
	else
	{
		if (atoi(argv[2]) == 1)
			kill(atoi(argv[1]), SIGUSR1);
		else if (atoi(argv[2]) == 2)
			kill(atoi(argv[1]), SIGUSR2);
	}
}
