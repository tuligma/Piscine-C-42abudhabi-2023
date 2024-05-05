/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:59:26 by npentini          #+#    #+#             */
/*   Updated: 2024/05/05 04:54:57 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	print_error(int error)
{
	if (error == -1)
		ft_putstr_fd("Memory allocation fails!!!\n", STDERR_FILENO);
	else
		ft_putstr_fd("Please provide the correct number of arguments\n", STDERR_FILENO);
	return (1);
}

void	print_table(int **table, int rows, int cols)
{
	int	x;
	int	j;

	x = -1;
	while (++x < rows)
	{
		j = -1;
		while (++j < cols)
		{
			ft_putchar_fd(table[x][j] + '0', STDOUT_FILENO);
			ft_putchar_fd(' ', STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}
