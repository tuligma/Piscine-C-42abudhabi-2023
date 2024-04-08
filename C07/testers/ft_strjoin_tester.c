#include "../includes/tuligma_C07.h"

int	main(void)
{
	char *str[] = {"Hello", "World", "!"};
	char *sep = " ";
	int	size = 3;
	char *result;
	int	i;

	printf("\n|ft_strjoin");
	printf("\n|size: 	 %d", size);
	printf("\n|sep: 	\"%s\"", sep);
	printf("\n|array: ");
	i = -1;
	while (++i < size)
	{
		if (i == 0)
			printf("{");
		printf("\"%s\"", str[i]);
		if (i != size - 1)
			printf(", ");
		else
			printf("}");
	}
	printf("\n-------------------------------");
	result = ft_strjoin(size, str, sep);
	printf("\nft_strjoin: \"%s\"\n\n", result);
	free(result);
}