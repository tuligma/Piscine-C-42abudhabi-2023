#include "../includes/tuligma_C02.h"

int	main()
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un e.puntos";

	printf("\nCapitalize first letter of each word by ft_strcapitalize\n");
	printf("\nBefore: %s\n", str);
	printf("\nAfter: %s\n\n", ft_strcapitalize(str));
}