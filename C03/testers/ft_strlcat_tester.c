#include "../includes/tuligma_C03.h"

int	main()
{
	char *src;
	char dest_ft[13] = "H";
	char dest_std[13] = "H";
	unsigned int size = 2;

	src = "World!";
	printf("\n strlcat vs ft_strlcat\n");
	printf("\nsrc string:		\"%s\"\n", src);
	printf("\ndest_ft string:		\"%s\"\n", dest_ft);
	printf("\ndest_ft string:		\"%s\"\n", dest_ft);
	printf("\nsize:		%d\n", size);
	printf("------------------------------\n");
	printf("\nresult:		%ld ->\"%s\" \n\n", strlcat(dest_std, src, size), dest_std);
	printf("\nresult:		%d ->\"%s\" \n\n", ft_strlcat(dest_ft, src, size), dest_ft);

}