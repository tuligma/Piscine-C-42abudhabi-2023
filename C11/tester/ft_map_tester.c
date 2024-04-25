#include "../includes/tuligma_C11.h"

int square_num(int n)
{
	return (n * n);
}

int	main(void)
{
	int	tab[10];
	int *tab_result;
	int	x;

	x = -1;
	while (++x < 10)
		tab[x] = x;
	printf("Before:	");
	fflush(stdout);
	ft_foreach(tab, 10, &ft_putnbr);
	printf("\n");
	tab_result = ft_map(tab, 10, &square_num);
	printf("After:	");
	fflush(stdout);
	ft_foreach(tab_result, 10, &ft_putnbr);
	printf("\n");
	return (0);
}