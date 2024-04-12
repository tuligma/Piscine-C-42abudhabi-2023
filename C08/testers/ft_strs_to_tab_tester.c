/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab_tester.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:31:22 by npentini          #+#    #+#             */
/*   Updated: 2024/04/12 21:41:34 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

struct s_stock_str *ft_str_to_tab(int ac, char **av);

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s <string1> <string2> ... <stringN>\n", argv[0]);
        return (1);
	}

	struct s_stock_str	*result;

	result = ft_str_to_tab(argc - 1, &argv[1]);

	if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Display the contents of the array of structures
    printf("\nResult:\n\n");
    int i = 0;
    while (result[i].str != NULL) {
        printf("Size:	%d\nString:	%s\nCopy:	%s\n\n", result[i].size, result[i].str, result[i].copy);
        i++;
    }

	 // Free memory allocated for the array of structures
    i = 0;
    while (result[i].str != NULL) {
        free(result[i].copy);
        i++;
    }
    free(result);

	return (0);
}