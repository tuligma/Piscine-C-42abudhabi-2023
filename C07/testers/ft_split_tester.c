#include "../includes/tuligma_C07.h"

int	main(void)
{
	char *str = "Hello World Banjo!";
	char *charset = " ";

	// Call ft_split to split the string
    char **result = ft_split(str, charset);
    
    // Print the resulting array of strings
    printf("Splitting the string \"%s\" using delimiter \"%s\":\n", str, charset);
    int i = 0;
    while (result[i] != 0) {
        printf("%s\n", result[i]);
        i++;
    }
    
    // Free memory allocated for the result
    i = 0;
    while (result[i] != 0) {
        free(result[i]);
        i++;
    }
    free(result);
    
    return 0;
}