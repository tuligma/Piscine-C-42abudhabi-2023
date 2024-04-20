/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:24:29 by npentini          #+#    #+#             */
/*   Updated: 2024/04/20 20:48:59 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	print_error(char *arg, int error_code)
{
	ft_putstr_err("ft_hexdump: ");
	ft_putstr_err(basename(arg));
	ft_putstr_err(": ");
	ft_putstr_err(strerror(error_code));
	ft_putstr_err("\nft_hexdump: all input file arguments failed\n");
	return (1);
}

int	print_error_arg(char *arg)
{
	if (arg[0] == '-' && arg[1] != 'C')
	{
		ft_putstr_err("ft_hexdump: invalid option -- \'");
		ft_putstr_err(arg + 1);
		ft_putstr_err("’\n");
		ft_putstr_err("Try 'ft_hexdump --help' for more information.\n");
	}
	return (1);
}

void	string_hex_print(char *str, unsigned int size)
{
	unsigned int	i;
	unsigned int	limit;

	i = -1;
	limit = 16;
	while (++i < size || i < limit)
	{
		if (i == 0 || i == limit)
			ft_putchar(' ');
		if (i % 1 == 0)
			ft_putchar(' ');
		if (i < size)
		{
			ft_putchar("0123456789abcdef"[((unsigned char)str[i]) / 16]);
			ft_putchar("0123456789abcdef"[((unsigned char)str[i]) % 16]);
		}
		else
			ft_putstr_out("  ");
		if (i == 7)
			ft_putchar(' ');
	}
	if ((i == size || i == limit))
		ft_putstr_out("  ");
}

void	string_print(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	ft_putchar('|');
	while (size--)
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	ft_putchar('|');
}
