#include "../includes/tuligma_C11.h"


int	main(void)
{

	int tab[100];
	int	x;
	
	x = -1;
	while (++x < 100)
		tab[x] = x;
	ft_foreach(tab, 100, &ft_putnbr);
	printf("\n");
	return (0);
}