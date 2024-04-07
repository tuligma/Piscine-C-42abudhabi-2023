#include "../includes/tuligma_C05.h"

int	main(int argc, char *argv[])
{
	int	result;

	if (argc != 3)
	{
		printf("\n\nPlease provide a number to calculate the factorial!\n\n");
		return (1);
	}

	result = ft_iterative_power(atoi(argv[1]), atoi(argv[2]));
	printf("\n\n(%s)power of (%s) is %d\n\n", argv[2], argv[1], result);
	return (0);
}