#include "../includes/tuligma_C01.h"

int	main()
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 12;
	b = 2;
	div = 0;
	mod = 0;
	printf("\n%d  /  %d \n", a, b);
	printf("\nBefore: div: %d mod: %d", div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("\nAfter: div: %d mod: %d\n", div, mod);
	return (0);
}
