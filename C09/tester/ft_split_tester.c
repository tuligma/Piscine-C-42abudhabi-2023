#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int	main(void)
{
	char *str = "A_B_C_D_E_F_G_H";
    char *charset = "_D";

    // Call ft_split to split the string
    char **result = ft_split(str, charset);
    
    // Print the resulting array of strings
    printf("Splitting the string \"%s\" using delimiter \"%s\":\n\n", str, charset);

    if (result != NULL) {
        int i = 0;
        while (result[i] != NULL) {
            printf("%d. %s\n", i + 1,result[i]);
            free(result[i]);
            i++;
        }
        free(result);   
    } else {
        printf("Splitting failed: Input string is NULL\n");
        printf("Return value of ft_split: %p\n", (void *)result);
    }
    
    return (0);
}