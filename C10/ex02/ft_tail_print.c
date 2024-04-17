/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:14:07 by npentini          #+#    #+#             */
/*   Updated: 2024/04/17 00:41:36 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_putstr_err(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(STDERR_FILENO, &str[i], 1);
}

void	ft_putstr_out(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(STDOUT_FILENO, &str[i], 1);
}

int	print_error(char *arg, int error_code)
{
	ft_putstr_err("tail: cannot open \'");
	ft_putstr_err(basename(arg));
	ft_putstr_err("\' for reading: ");
	ft_putstr_err(strerror(error_code));
	ft_putstr_err("\n");
	return (1);
}

int	print_error_byte(char *arg)
{
	if (arg[0] == '-' && arg[1] != 'c')
	{
		ft_putstr_err("tail: invalid option -- \'");
		ft_putstr_err(arg + 1);
		ft_putstr_err("’");
		ft_putstr_err("\n");
	}
	else
	{
		ft_putstr_err("tail: invalid number of bytes: ‘");
		ft_putstr_err(arg);
		ft_putstr_err("’");
		ft_putstr_err("\n");
	}
	return (1);
}

void	print_head(char *arg)
{
	ft_putstr_out("==> ");
	ft_putstr_out(arg);
	ft_putstr_out(" <==\n");
}
