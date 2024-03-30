#include "../includes/tuligma_C01.h"

int	main()
{
	int	a;
	int	b;

	a = 100;
	b = 8;

	printf("\n%d  /  %d \n", a, b);
	printf("\nBefore: a: %d b: %d", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("\nAfter: a: %d b: %d\n", a, b);
}