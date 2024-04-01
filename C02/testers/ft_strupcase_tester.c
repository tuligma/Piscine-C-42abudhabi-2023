#include "../includes/tuligma_C02.h"

int	main()
{
	char	str[] = "this is  123 all upperCASE!";;
	char	*x;

	printf("\nTransformation by ft_strupcase\n");
	printf("\nOriginal string:	\"%s\"", str);
	x = ft_strupcase(str);
	printf("\nManipulated string:	\"%s\"\n\n", x);//
	return (0);
}