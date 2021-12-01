#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	i;

	i = 10;
	printf("COUNT_DOWN\n");
	while (i >= 0)
	{
		printf("%dsec\n", i);
		sleep(1);
		i--;
	}
	return (0);
}
