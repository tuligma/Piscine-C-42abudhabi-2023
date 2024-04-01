#include "../includes/tuligma_C02.h"

int	main()
{
	char	*src;
	char	dest[12];
	unsigned int n;

	src = "Hello";
	n = 0;
	printf("\nstrcpy() vs ft_strcpy\n");
	strncpy(dest, src, n);
	if (dest[0] == '\0')
		printf("\nthere is a null terminator\n");
	else
		printf("\nthere is no null terminator\n");
	printf("\nstrcpy:		%s\n", dest);
	memset(dest, '0', 12);
	printf("reset:		%s\n", dest);
	ft_strncpy(dest, src, n);
	if (dest[0] == '\0')
		printf("\nthere is a null terminator\n");
	else
		printf("\nthere is no null terminator\n");
	printf("ft_strcpy:	%s\n\n", dest);
	return (0);
}