/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 04:40:11 by npentini          #+#    #+#             */
/*   Updated: 2024/04/08 13:09:47 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// chessboard initialization
void	chessboard_initialization(char board[10][10], int size)
{
	int	c;
	int	r;

	r = -1;
	while (++r < size)
	{
		c = -1;
		while (++c < size)
			board[r][c] = '#';
	}
}

// checking for conflicts on row and column, leftdiagonal, rightdiagonal
int	queen_checker(char board[10][10], int row, int col, int size)
{
	int	i;
	int	r;
	int	c;

	i = -1;
	while (++i < size)
	{
		if (board[row][i] == 'Q' || board[i][col] == 'Q')
			return (1);
	}
	r = row;
	c = col;
	while (r >= 0 && c >= 0)
	{
		if (board[r--][c--] == 'Q')
			return (1);
	}
	r = row;
	c = col;
	while (r < size && c >= 0)
	{
		if (board[r++][c--] == 'Q')
			return (1);
	}
	return (0);
}

// printing the queens posible positions per column;
void	print_queens(char board[10][10], int size)
{
	char	digit;
	int		row;
	int		col;

	col = -1;
	while (++col < size)
	{
		row = -1;
		while (++row < size)
		{
			if (board[row][col] == 'Q')
			{
				digit = row + '0';
				write(1, &digit, 1);
				break ;
			}
		}
	}
	write(1, "\n", 1);
}

//placement of queen recursively and backtracking
int	puzzle_solver(char board[10][10], int col, int size)
{
	int	row;
	int	count;

	if (col >= size)
	{
		print_queens(board, size);
		return (1);
	}
	count = 0;
	row = -1;
	while (++row < size)
	{
		if (!queen_checker(board, row, col, size))
		{
			board[row][col] = 'Q';
			count += puzzle_solver(board, col + 1, size);
			board[row][col] = '#';
		}
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10][10];

	chessboard_initialization(board, 10);
	return (puzzle_solver(board, 0, 10));
}
