/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:42:07 by npentini          #+#    #+#             */
/*   Updated: 2024/05/04 00:56:52 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_edge(int x)
{
	int	j;

	j = -1;
	while (++j < x)
	{
		if (j == 0 || j == x - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	ft_putchar('\n');
}

void	print_inner(int y)
{
	int	j;

	j = -1;
	while (++j < y)
	{
		if (j == 0 || j == y - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
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
		ft_putchar('o');
		ft_putchar('\n');
		return ;
	}
	while (++i < y)
	{
		if (i == 0 || i == y - 1)
			print_edge(x);
		else
			print_inner(y);
	}
}
