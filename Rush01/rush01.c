/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:25:21 by npentini          #+#    #+#             */
/*   Updated: 2024/05/05 05:53:57 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

void initial_mapping(int **arg, int **table)
{
	int	x;
	int	j;

	x = 0;
	while (arg[x] != NULL)
	{
		if (x < 4)
		{
			j = 0;
			if (*arg[x] == 1)
				table[j][x] = 4;
			if (*arg[x] == 4)
			{
				while (j < 4)
				{
					table[j][x] = j + 1;
					j++;
				}
			}
		}
		x++;
	}
}

int	**rush01(int **arg)
{
	int	**table;
	int rows;
	int cols;

	(void)arg;
	rows = 4;
	cols = 4;
	table = table_creation(cols, rows);
	if (table == NULL)
		return (NULL);
	initial_mapping(arg, table);
	print_table(table, rows, cols);
	return (table);
}

int	main(int argc, char *argv[])
{
	int		**arg;
	int		**table;

	if (argc != 2)
		return (print_error(2));
	arg = arg_to_int(argv[1]);
	if (arg == NULL)
		return (print_error(-1));
	table = rush01(arg);
	if (table == NULL)
		return (print_error(-1));
	free_array(arg);
	free_array(table);
	return (0);
}
