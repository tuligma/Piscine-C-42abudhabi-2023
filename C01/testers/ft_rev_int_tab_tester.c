#include "../includes/tuligma_C01.h"

int	main()
{
	int	x[6] = {1, 3, 9, 5 , 7, 4};
	int	size;
	int i;

	size = 6;
	printf("Before:	");
	i = 0;
	while (i < size)
	{
		if (i == 0)
			printf("[");
		printf("%d", x[i]);
		if (i != size - 1)
			printf(", ");
		if (i + 1 == size)
			printf("]");
		i++;
	}
	ft_rev_int_tab(x, size);
	printf("\nAfter:	");
	i = 0;
	while (i < size)
	{
		if (i == 0)
			printf("[");
		printf("%d", x[i]);
		if (i != size - 1)
			printf(", ");
		if (i + 1 == size)
			printf("]");
		i++;
	}
	printf("\n");
	return (0);
}