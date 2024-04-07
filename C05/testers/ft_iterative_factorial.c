#include "../includes/tuligma_C05.h"

int	main(int argc, char *argv[])
{
	int	result;

	if (argc != 2)
	{
		printf("\n\nPlease provide a number to calculate the factorial!\n\n");
		return (1);
	}

	result = ft_iterative_factorial(atoi(argv[1]));
	printf("\n\nFactorial of (%s) is %d\n\n", argv[1], result);
	return (0);
}