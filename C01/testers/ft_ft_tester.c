#include "../includes/tuligma_C01.h"

int main()
{
	int *nbr;
	int	i;

	i = 20;
	nbr = &i;
	printf("\n<nbr value before and after>\n");
	printf("\nbefore:%d", *nbr);
	ft_ft(nbr);
	printf("\nafter:%d\n", *nbr);
	return (0);
}
