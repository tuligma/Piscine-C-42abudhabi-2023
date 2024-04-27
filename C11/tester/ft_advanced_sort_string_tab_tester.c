#include "../includes/tuligma_C11.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}


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
	ft_advanced_sort_string_tab(array, &ft_strcmp);
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