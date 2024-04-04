#include "../includes/tuligma_C04.h"

int	main(void)
{
	char *str;

	str = "the total length of this string is   (42)!";
	printf("\nstrlen vs ft_strlen\n");
	printf("\nstr: \"%s\"", str);
	printf("\nstrlen: %ld", strlen(str));
	printf("\nstrlen: %d\n\n", ft_strlen(str));
}