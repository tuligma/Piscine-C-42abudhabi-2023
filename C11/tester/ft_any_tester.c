#include "../includes/tuligma_C11.h"

int	ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
			return (0);
		i++;
	}
	return (1);
}


int	main(void)
{
	char *str[4] = {"78", "ab", "9", "123"};
	int result;
	int x;

	printf("\nis the array: \"");
	x = -1;
	while (++x < 4)
		printf("%s ", str[x]);
	printf("\" contains any alphabet characters?\n\n");
	result = ft_any(str, &ft_str_is_alpha);
	printf("Result: %d\n\n", result);

}