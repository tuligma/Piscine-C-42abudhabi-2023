/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 23:42:27 by npentini          #+#    #+#             */
/*   Updated: 2024/03/30 22:53:41 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ceiling(int n)
{
	int		last;
	int		digit;
	int		i;

	digit = 10 - n;
	i = 0;
	last = 0;
	while (i < n)
	{
		last = last * 10 + digit;
		digit++;
		i++;
	}
	return (last);
}

void	print(int n, int *x)
{
	int		last;
	int		i;

	last = 0;
	i = -1;
	while (++i < n)
	{
		ft_putchar(x[i] + '0');
		last = last * 10 + x[i];
	}
	if (!(last == ceiling(n)))
		write(1, ", ", 2);
}

void	generate(int n, int index, int current, int *x)
{
	int		i;

	if (index == n)
	{
		print(n, x);
		return ;
	}
	i = current + 1;
	while (i <= 9)
	{
		x[index] = i;
		generate(n, index + 1, i, x);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int		x[10];

	generate(n, 0, -1, x);
}
