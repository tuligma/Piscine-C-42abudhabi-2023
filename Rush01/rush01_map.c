/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 05:01:38 by npentini          #+#    #+#             */
/*   Updated: 2024/05/06 05:27:45 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	rowlf_map(int **arg, int **table, int rows)
{
	int	x;
	int	j;
	int	i;

	i = -1;
	j = 0;
	while (arg[++i] != NULL && i < rows)
	{
		x = 0;
		j = i;
		if (*arg[i] == 1)
			table[j][x] = 4;
		if (*arg[i] == 4)
		{
			while (x < 4)
			{
				table[j][x] = x + 1;
				x++;
			}
			continue ;
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
	while (arg[++i] != NULL && i < cols)
	{
		j = 0;
		x = i;
		if (*arg[i] == 4)
		{
			while (j < 4)
			{
				table[j][x] = j + 1;
				j++;
			}
			continue ;
		}
		else if (*arg[i] == 1)
			table[j][x] = 4;
		else if (*arg[i] == 2)
			table[j + 1][x] = 4;
		else if (*arg[i] == 3 && table[j][x] == 2)
			table[j + 1][x] = 3;
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

void	verifier_remaining(int **arg, int **table, int rows, int cols)
{
	int	x;
	int	j;

	x = -1;
	while (++x < rows)
	{
		j = cols;
		while (--j >= 0)
		{
			if (table[j][x] == 0)
			{
				if (*arg[x] == 2 && table[j - 1][x] == 4)
					table[j][x] = 1;
			}
		}
	}
}
