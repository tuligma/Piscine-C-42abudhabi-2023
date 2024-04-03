#include "../includes/tuligma_C02.h"

int	main()
{
	char src[0xFF + 10];
	char str[] = "Coucou\ntu vas bien ?";
     int     i;

    i = 1;
    while (i <= 0xFF)
    {
        src[i - 1] = i;
        i++;
    }
    src[i - 1] = 0;

	printf("\nTransform non printable to hexadecimal (lowercase)\n");
	printf("\nOriginal string: %s\n", "Coucou\ntu vas bien ?");
	printf("\nTransformed string: ");
	fflush(stdout);
	ft_putstr_non_printable(str);
	printf("\n----------------------------------------------");
	printf("\nOriginal string: %s\n", src);
	printf("\nTransformed string: ");
	fflush(stdout);
	ft_putstr_non_printable(src);
	printf("\n");
	return (0);
}