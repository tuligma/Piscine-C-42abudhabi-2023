#include "../includes/tuligma_C11.h"

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

int main(void)
{
	char *str[] = {"Hello", "", "world!", " ", " 42"};
	int length;
	int x;

	printf("\n");
	length = 5;
	x = -1;
	while (++x < length)
		printf("string %d.	\"%s\"\n", x + 1, str[x]);
	printf("\n\nCount: %d\n\n", ft_count_if(str, length, &ft_strlen));
	return (0);
}