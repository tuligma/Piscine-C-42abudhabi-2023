#include "../includes/tuligma_C02.h"

int	main()
{
	char	str[] = "tHIs iS  123?!\\] ALL LOWERCASE!";;

	printf("\nTransformation by ft_strlowcase\n");
	printf("\nOriginal string:	\"%s\"", str);
	printf("\nManipulated string:	\"%s\"\n\n", ft_strlowcase(str));//
	return (0);
}