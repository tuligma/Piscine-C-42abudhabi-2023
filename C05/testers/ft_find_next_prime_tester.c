#include "../includes/tuligma_C05.h"

int	main(int argc, char *argv[])
{
	int	result;

	if (argc != 2)
	{
		printf("\n\nPlease provide a number to check if it is a prime number!\n\n");
		return (1);
	}

	result = ft_find_next_prime(atoi(argv[1]));
	printf("\n\nThen next prime number to (%s) is a (%d)\n\n", argv[1], result);
	return (0);
}