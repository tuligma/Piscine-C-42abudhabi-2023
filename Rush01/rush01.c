/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:25:21 by npentini          #+#    #+#             */
/*   Updated: 2024/05/06 00:10:43 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

void	verifier_cols(int **table, int rows, int cols)
{
	int	x;
	int	j;
	int	box;

	x = -1;
	while (++x < cols)
	{
		box = 0;
		j = -1;
		while (++j < rows)
		{
			if (j == rows - 1 && table[j - 1][x] != 0)
				table[j][x] = 10 - box;
			box += table[j][x];	
		}
	}
}


void	verifier_rows(int **table, int rows, int cols)
{
	int	x;
	int	j;
	int	box;

	j = -1;
	while (++j < rows)
	{
		box = 0;
		x = -1;
		while (++x < cols)
		{
			if (x == cols - 1 && table[j][x - 1] != 0)
				table[j][x] = 10 - box;
			box += table[j][x];	
		}
	}
}

void	rowlf_map(int **arg, int **table, int rows)
{
	int	x;
	int	j;
	int	i;

	i = -1;
	j = 0;
	while (arg[++i] != NULL && i < rows)
	{
		j = i;
		if (*arg[i] == 1)
			table[j][x] = 4;
		if (*arg[i] == 4)
		{
			x = 0;
			while (x < 4)
			{
				table[j][x] = x + 1;
				x++;
			}
			x = 0;
		}
		if (*arg[i] == 2)
			table[j][x + 1] = 4;
	}
}

void	colup_map(int **arg, int **table, int cols)
{
	int	x;
	int	j;
	int	i;

	i = -1;
	j = 0;
	while (arg[++i] != NULL && i < cols)
	{
		x = i;
		if (*arg[i] == 1)
			table[j][x] = 4;
		if (*arg[i] == 4)
		{
			j = 0;
			while (j < 4)
			{
				table[j][x] = j + 1;
				j++;
			}
			j = 0;
		}
		if (*arg[i] == 2)
			table[j + 1][x] = 4;
		if (*arg[i] == 3 && table[j][x] == 2)
			table[j + 1][x] = 3;
	}
}

void	initial_mapping(int **arg, int **table, int rows, int cols)
{
	rowlf_map(arg + 8, table, rows);
	colup_map(arg, table, cols);
	verifier_rows(table, rows, cols);
	verifier_cols(table, rows, cols);
}

int	**rush01(int **arg)
{
	int	**table;
	int	rows;
	int	cols;

	(void)arg;
	rows = 4;
	cols = 4;
	table = table_creation(cols, rows);
	if (table == NULL)
		return (NULL);
	initial_mapping(arg, table, rows, cols);
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
