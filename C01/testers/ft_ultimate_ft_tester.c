#include "../includes/tuligma_C01.h"

int main()
{
	int *********x9;
	int ********x8;
	int *******x7;
	int ******x6;
	int *****x5;
	int ****x4;
	int ***x3;
	int **x2;
	int *x1;
	int	i;

	i = 20;
	x9 = &x8;
	x8 = &x7;
	x7 = &x6;
	x6 = &x5;
	x5 = &x4;
	x4 = &x3;
	x3 = &x2;
	x2 = &x1;
	x1 = &i;
	
	printf("\n<nbr value before and after>\n");
	printf("\nbefore:%d", i);
	ft_ultimate_ft(x9);
	printf("\nafter:%d\n", i);
	return (0);
}
