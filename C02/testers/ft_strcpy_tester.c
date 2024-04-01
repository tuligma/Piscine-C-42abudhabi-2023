#include "../includes/tuligma_C02.h"

int	main()
{
	char	*src;
	char	dest[12];

	src = "Hello World!";
	printf("\nstrcpy() vs ft_strcpy\n");
	strcpy(dest, src);
	printf("\nstrcpy:		%s\n", dest);
	memset(dest, '0', 12);
	printf("reset:		%s\n", dest);
	ft_strcpy(dest, src);
	printf("ft_strcpy:	%s\n\n", dest);
	return (0);
}