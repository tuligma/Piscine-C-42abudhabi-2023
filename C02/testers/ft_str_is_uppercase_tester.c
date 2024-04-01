#include "../includes/tuligma_C02.h"

int main()
{
	char	*str;
	int		x;

	str = "ZaB";
	printf("\n is \"%s\" uppercase or not?\n", str);
	x = ft_str_is_uppercase(str);
	if (x)
		printf("\n\t\"YES\" -> (%d)\n\n", x);
	else
		printf("\n\t\"NO\" -> (%d)\n\n", x);
	return (0);

}