#include "../includes/tuligma_C02.h"

int main()
{
	char	*str;
	int		x;

	str = "";
	printf("\n is \"%s\" printable or not?\n", str);
	x = ft_str_is_printable(str);
	if (x)
		printf("\n\t\"YES\" -> (%d)\n\n", x);
	else
		printf("\n\t\"NO\" -> (%d)\n\n", x);
	return (0);

}