#include "../includes/tuligma_C02.h"

int	main(void)
{
	char	dest1[13] = "efghijklm";
	char	dest2[13] = "efghijklm";
	char	src[] = "abasdf";
	unsigned int	size;
	unsigned int	result;
	unsigned int	result2;

	size = 8;
	printf("\ntotal size by ft_strlcpy\n");
	printf("\ndest: %s", dest1);
	printf("\ndest: %s\n", dest2);
	printf("src: %s\n", src);
	result = strlcpy(dest1, src, size);
	printf("----------------------");
	printf("\nsrc: %s", src);
	printf("\nsize: %d\n", result);
	printf("dest1: %s\n", dest1);
	result2 = ft_strlcpy(dest2, src, size);
	printf("----------------------");
	printf("\nsrc: %s", src);
	printf("\nsize: %d\n", result2);
	printf("dest2: %s\n", dest2);
	return (0);
}