/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:58:20 by npentini          #+#    #+#             */
/*   Updated: 2024/05/06 05:31:17 by npentini         ###   ########.fr       */
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
	table[x] = NULL;
	return (table);
}

int	checker(int **table)
{
	int	x;
	int	j;
	int	box;

	j = -1;
	box = 0;
	while (++j < 4)
	{
		x = -1;
		while (++x < 4)
			box += table[j][x];
	}
	x = -1;
	while (++x < 4)
	{
		j = -1;
		while (++j < 4)
			box += table[j][x];
	}
	if (box != 80)
		return (1);
	return (0);
}

int	mapping(int **arg, int **table, int rows, int cols)
{
	int	status;

	rowlf_map(arg + 8, table, rows);
	colup_map(arg, table, cols);
	verifier_rows(table, rows, cols);
	verifier_cols(table, rows, cols);
	verifier_remaining(arg + 4, table, rows, cols);
	verifier_rows(table, rows, cols);
	verifier_cols(table, rows, cols);
	status = checker(table);
	if (status == 1)
		return (print_error());
	return (0);
}

int	**rush01(int **arg)
{
	int	**table;
	int	rows;
	int	cols;
	int	status;

	(void)arg;
	rows = 4;
	cols = 4;
	table = table_creation(cols, rows);
	if (table == NULL)
		return (NULL);
	status = mapping(arg, table, rows, cols);
	if (status == 1)
		return (NULL);
	print_table(table, rows, cols);
	return (table);
}
