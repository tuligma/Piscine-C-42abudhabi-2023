/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:42:07 by npentini          #+#    #+#             */
/*   Updated: 2024/05/04 01:02:21 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_edge_top(int x)
{
	int	j;

	j = -1;
	while (++j < x)
	{
		if (j > 0 && j < x - 1)
			ft_putchar('B');
		else
		{
			if (j == 0)
				ft_putchar('A');
			else
				ft_putchar('C');
		}
	}
	ft_putchar('\n');
}

void	print_inner(int x)
{
	int	j;

	j = -1;
	while (++j < x)
	{
		if (j > 0 && j < x - 1)
			ft_putchar(' ');
		else
			ft_putchar('B');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int		i;

	i = -1;
	if (x == 0 || y == 0)
	{
		ft_putchar('\n');
		return ;
	}
	else if (x == 1 && y == 1)
	{
		ft_putchar('A');
		ft_putchar('\n');
		return ;
	}
	while (++i < y)
	{
		if (i > 0 && i < y - 1)
			print_inner(x);
		else
			print_edge_top(x);
	}
}
