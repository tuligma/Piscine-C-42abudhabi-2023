/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:59:26 by npentini          #+#    #+#             */
/*   Updated: 2024/05/06 05:30:35 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	print_error(void)
{
	ft_putstr_fd("ERROR\n", STDERR_FILENO);
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
			if (j < cols - 1)
				ft_putchar_fd(' ', STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}
