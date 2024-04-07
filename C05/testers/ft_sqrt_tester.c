#include "../includes/tuligma_C05.h"

int	main(int argc, char *argv[])
{
	int	result;

	if (argc != 2)
	{
		printf("\n\nPlease provide a number to find a perfect square!\n\n");
		return (1);
	}

	result = ft_sqrt(atoi(argv[1]));
	if (result)
		printf("\n\nNumber (%s) has a perfect square root of %d!\n\n", argv[1], result);
	else
		printf("\n\nNumber (%s) has no perfect square!\n\n", argv[1]);
		
	return (0);
}