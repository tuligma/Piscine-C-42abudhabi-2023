#include "../includes/tuligma_C11.h"

int	ft_intcmp(int n1, int n2)
{
	return (n1 - n2);
}

int	main(void)
{
	int	tab[] = {9, 8, 7, 6, 5};
	int length = 5;
	int	x = -1;

	printf("\nis array tab: {");
	while (++x < length)
	{
		printf("%d", tab[x]);
		if (x != length - 1)
			printf(", ");
	}
	printf("} sorted?\n");
	if (ft_is_sort(tab, length, &ft_intcmp) == 1)
		printf("\nYES!!\n\n");
	else
		printf("\nNO!!\n\n");
	return (0);
}