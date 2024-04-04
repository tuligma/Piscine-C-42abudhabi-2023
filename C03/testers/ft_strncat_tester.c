#include "../includes/tuligma_C03.h"

int	main()
{
	char *src;
	char dest1[13] = "Hello";
	char dest2[13] = "Hello";

	src = " World!";
	printf("\n strncat vs ft_strncat\n");
	printf("\nsrc string:		%s\n", src);
	printf("\ndest1 string:		%s -> size: %d -> for strncat\n", dest1, 13);
	printf("\ndest1 string:		%s -> size: %d -> for ft_strncat\n\n", dest2, 13);
	printf("------------------------------\n");
	printf("\nresult string:		%s -> strncat\n\n", strncat(dest1, src, 7));
	printf("\nresult string:		%s -> ft_strncat\n\n", ft_strncat(dest2, src, 7));

}