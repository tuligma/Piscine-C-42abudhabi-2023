#include "../includes/tuligma_C07.h"

int	main(int argc, char *argv[])
{
	int	*range = NULL;
	int	result;
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
	result = ft_ultimate_range(&range, min, max);
	printf("\n\n the total count of range from %d to %d is -> (%d) -> ", atoi(argv[1]), atoi(argv[2]), result);
	i = 0;
	while (i < max - min)
	{
		printf("%d", range[i]);
		if (i++ != max - min - 1)
			printf(" | ");
	}
	printf("\n\n");
	free(range);
	return 0;
}