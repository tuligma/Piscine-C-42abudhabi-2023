/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:23:23 by npentini          #+#    #+#             */
/*   Updated: 2024/04/24 01:06:08 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	print_error_flag(char *arg)
{
	ft_putstr_fd("hexdump: invalid option -- \'", STDERR_FILENO);
	ft_putstr_fd(basename(arg + 1), STDERR_FILENO);
	ft_putstr_fd("\'\nTry \'ft_hexdump --help\' for more information.\n",
		STDERR_FILENO);
	return (1);
}

int	print_error(char *arg, int error_code)
{
	ft_putstr_fd("ft_hexdump: ", STDERR_FILENO);
	ft_putstr_fd(basename(arg), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(error_code), STDERR_FILENO);
	// ft_putstr_fd("\nft_hexdump: all input ", STDERR_FILENO);
	// ft_putstr_fd("file arguments failed\n", STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (1);
}

void	print_hex(char c)
{
	if (c / 16 < 10)
		ft_putchar_fd('0' + (c / 16), STDOUT_FILENO);
	else
		ft_putchar_fd('a' + (c / 16) - 10, STDOUT_FILENO);
	if (c % 16 < 10)
		ft_putchar_fd('0' + (c % 16), STDOUT_FILENO);
	else
		ft_putchar_fd('a' + (c % 16) - 10, STDOUT_FILENO);
}

void	string_hex_print(char *str, int size)
{
	int	i;
	int	limit;

	i = -1;
	limit = 16;
	while (++i < size || i < limit)
	{
		if (i == 0 || i == limit)
			ft_putstr_fd(" ", STDOUT_FILENO);
		if (i % 1 == 0)
			ft_putstr_fd(" ", STDOUT_FILENO);
		if (i < size)
		{
			print_hex(str[i]);
		}
		else
			ft_putstr_fd("  ", STDERR_FILENO);
		if (i == 7)
			ft_putstr_fd(" ", STDERR_FILENO);
	}
	if ((i == size || i == limit))
		ft_putstr_fd("  ", STDERR_FILENO);
}

void	string_print(char *str, int size)
{
	unsigned int	i;

	if (size == 0)
		return ;
	i = 0;
	ft_putstr_fd("|", STDERR_FILENO);
	while (size--)
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	ft_putstr_fd("|", STDERR_FILENO);
}
