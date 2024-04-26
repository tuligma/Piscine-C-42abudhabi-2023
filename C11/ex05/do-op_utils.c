/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:05:57 by npentini          #+#    #+#             */
/*   Updated: 2024/04/27 03:36:24 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	x;

	x = -1;
	while (str[++x] != '\0')
		ft_putchar_fd(str[x], fd);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", STDOUT_FILENO);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', STDOUT_FILENO);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar_fd(nb % 10 + '0', STDOUT_FILENO);
}

int	ft_atoi(char *str)
{
	int	x;
	int	state;
	int	result;

	x = 0;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == ' ' || str[x] == '\n')
		x++;
	state = 0;
	while (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			state++;
		x++;
	}
	result = 0;
	while (str[x] >= '0' && str[x] <= '9')
		result = result * 10 + (str[x++] - '0');
	if (state % 2)
		result *= -1;
	return (result);
}

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}
