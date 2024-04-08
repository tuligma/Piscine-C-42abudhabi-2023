/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:41:59 by npentini          #+#    #+#             */
/*   Updated: 2024/04/08 12:42:10 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tuligma_C05.h"

void	printboard(char board[5][5], int size)
{
	int	r;
	int	c;

	r = -1;
	while (++r < size)
	{
		c = -1;
		while (++c < size)
		{
			write(1, &board[r][c], 1);
			if (c != size - 1)
				write(1, " | ", 3);
		}
		write(1, "\n", 1);
	}
}
