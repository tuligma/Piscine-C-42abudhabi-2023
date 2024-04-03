#include "../includes/tuligma_C03.h"

int	main()
{
	char *src;
	char dest[13] = "Hello";

	src = " World!";
	printf("\n strcat vs ft_strcat\n");
	printf("\nsrc string:		%s\n", src);
	printf("\ndest string:		%s\n", dest);
	printf("\ndest size:		%d\n", 13);
	printf("------------------------------\n");
	printf("\nresult string:		%s\n\n", ft_strcat(dest, src));

}