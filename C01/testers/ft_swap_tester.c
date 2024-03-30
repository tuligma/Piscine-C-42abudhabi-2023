#include "../includes/tuligma_C01.h"


int	main()
{
	int		*a;
	int		*b;
	int		x;
	int		y;

	x = 22;
	y = 33;
	a = &x;
	b = &y;
	printf("\n<Swaping of a and b values>\n");
	printf("\nBefore: A->(%d)  B->(%d)\n", x, y);
	ft_swap(a, b);
	printf("\nAfter: A->(%d)  B->(%d)\n", x, y);

}