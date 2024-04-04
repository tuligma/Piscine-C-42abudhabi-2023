#include "../includes/tuligma_C04.h"

int	main(void)
{
	char *str;

	str = "the total length of this string is   (42)!";
	printf("\nprintf vs puts vs ft_strlen\n");
	printf("\nprintf: \"%s\"", str);
	puts("\n\nputs:");
	puts(str);
	ft_putstr("\nft_putstr: ");
	ft_putstr(str);
	ft_putstr("\n\n");
}