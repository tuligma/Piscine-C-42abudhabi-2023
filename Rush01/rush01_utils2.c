/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:58:20 by npentini          #+#    #+#             */
/*   Updated: 2024/05/05 04:55:32 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**arg_to_int(char *str)
{
	int	**arg_arr;
	int	x;
	int	j;

	arg_arr = (int **)malloc(sizeof(int *) * (16 + 1));
	if (arg_arr == NULL)
		return (NULL);
	x = 0;
	j = -1;
	while (str[x] != '\0')
	{
		if (str[x] != ' ')
		{
			arg_arr[++j] = malloc(sizeof(int));
			if (arg_arr[j] == NULL)
				return (free_fail(arg_arr, j));
			*arg_arr[j] = str[x] - '0';
		}
		x++;
	}
	arg_arr[++j] = NULL;
	return (arg_arr);
}

int	**table_creation(int rows, int cols)
{
	int	**table;
	int	x;
	int	j;

	table = (int **)malloc(sizeof(int *) * (rows + 1));
	if (table == NULL)
		return (NULL);
	x = -1;
	while (++x < rows)
	{
		table[x] = (int *)malloc(sizeof(int) * cols);
		if (table[x] == NULL)
			return (free_fail(table, x));
		j = -1;
		while (++j < cols)
			table[x][j] = 0;
	}
	table[x]= NULL;
	return (table);
}