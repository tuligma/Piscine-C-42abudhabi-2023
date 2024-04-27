#include "../includes/tuligma_C11.h"

int	main(void)
{
	char *array[] = {"zebra", "frost", "grapes", "apple", "Coal", NULL};
	int len = 5;

	int x;

	printf("\nBefore:");
	printf("\narray: {");
	x = -1;
	while (array[++x] != NULL)
	{
		printf("\"%s\"", array[x]);
		if (x < len - 1)
			printf(", ");
	}
	printf("}\n");
	ft_sort_string_tab(array);
	printf("\nAfter:");
	printf("\narray: {");
	x = -1;
	while (array[++x] != NULL)
	{
		printf("\"%s\"", array[x]);
		if (x < len - 1)
			printf(", ");
	}
	printf("}\n\n");
	return (0);
}