#include "../includes/tuligma_C01.h"

int	main()
{
	int	x[5] = {8, 2, 5, 3, 6};
	int size;
	int	i;

	size = 5;
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
	ft_sort_int_tab(x, size);
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
}