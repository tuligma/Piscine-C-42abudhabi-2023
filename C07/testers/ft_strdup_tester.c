#include "../includes/tuligma_C07.h"

int	main(int argc, char *argv[])
{
	char	*src;
	char 	*result1;
	char	*result2;
	
	if (argc <= 1)
	{
		printf("\nPlease provide a string to be duplicated");
		return (1);
	}
	src = argv[1];
	printf("\nstrdup vs ft_strdup\n");
		printf("\nsrc:    	%s <- string	%p <- address of str	%p <-address of src\n", src, src, &src);
	result1 = strdup(src);
	printf("\nstrdup:   	%s <- string	%p <- address of str	%p <- address of ptr", result1, result1, &result1);
	free(result1);
	result2 = ft_strdup(src);
	printf("\nft_strdup:	%s <- string	%p <- address of str	%p <- address of ptr\n\n", result2, result2, &result2);
	free(result2);
	return (0);
}