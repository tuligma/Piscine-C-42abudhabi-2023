#include "../includes/tuligma_C05.h"

int	main(int argc, char *argv[])
{
	int	result;

	if (argc != 2)
	{
		printf("\n\nPlease provide a number to check if it is a prime number!\n\n");
		return (1);
	}

	result = ft_is_prime(atoi(argv[1]));
	if (result)
		printf("\n\nNumber (%s) is a prime number!\n\n", argv[1]);
	else
		printf("\n\nNumber (%s) it not a prime number!\n\n", argv[1]);
		
	return (0);
}