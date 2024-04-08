#include "../includes/tuligma_C07.h"

int	main(int argc, char *argv[])
{
	int	*result;
	int	i;
	int	min;
	int	max;

	if (argc != 3)
	{
		printf("\n Please provide minimum number and maximum number!\n\n");
		return (1);
	}
	min = atoi(argv[1]);
	max = atoi(argv[2]);
	result = ft_range(min, max);
	printf("\n\n the range from %d to %d is ->  ", atoi(argv[1]), atoi(argv[2]));
	if (!result)
		printf("NULL\n\n");
	i = 0;
	while (i < max - min)
	{
		printf("%d", result[i]);
		if (i++ != max - min - 1)
			printf(" | ");
	}
	printf("\n\n");
	free(result);
	return 0;
}