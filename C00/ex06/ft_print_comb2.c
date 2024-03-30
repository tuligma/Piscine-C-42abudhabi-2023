/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 04:59:11 by npentini          #+#    #+#             */
/*   Updated: 2024/03/29 22:57:25 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int		x[2];

	x[0] = 0;
	while (x[0] < 99)
	{
		x[1] = x[0];
		while (++x[1] < 100)
		{
			ft_putchar(x[0] / 10 + '0');
			ft_putchar(x[0] % 10 + '0');
			ft_putchar(' ');
			ft_putchar(x[1] / 10 + '0');
			ft_putchar(x[1] % 10 + '0');
			if (x[0] != 98 || x[1] != 99)
				write(1, ", ", 2);
		}
		x[0]++;
	}
}
