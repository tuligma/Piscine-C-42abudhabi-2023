/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 03:27:37 by npentini          #+#    #+#             */
/*   Updated: 2024/04/20 04:20:52 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	print_head(char *arg)
{
	ft_putstr_out("==> ");
	ft_putstr_out(basename(arg));
	ft_putstr_out(" <==\n");
}

int	print_error(char *arg, int error_code)
{
	ft_putstr_err("ft_tail: cannot open \'");
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
		ft_putstr_err("ft_tail: invalid option -- \'");
		ft_putstr_err(arg + 1);
		ft_putstr_err("’\n");
		ft_putstr_err("Try './ft_tail --help' for more information.\n");
	}
	else if (arg[0] == '-' && arg[1] == 'c')
	{
		ft_putstr_err("ft_tail: option requires an argument -- \'");
		ft_putstr_err(arg + 1);
		ft_putstr_err("’\n");
		ft_putstr_err("Try './ft_tail --help' for more information.\n");
	}
	else
	{
		ft_putstr_err("ft_tail: invalid number of bytes: ‘");
		ft_putstr_err(basename(arg));
		ft_putstr_err("’\n");
	}
	return (1);
}

int	print_single_out(char *arg, int byte_size, int *prev_result, int argc)
{
	char	*buff;
	int		result;

	result = execute_read(arg, byte_size, &buff);
	if (result == -1)
		return (result);
	if (argc > 4 && result == 0)
		print_head(arg);
	ft_putstr_out(buff + (total_buff_size(arg, byte_size, 1) - byte_size));
	free(buff);
	*prev_result = result;
	return (0);
}

int	print_multi_out(char *arg, int byte_size, int *prev_result, int argc)
{
	char	*buff;
	int		result;

	result = execute_read(arg, byte_size, &buff);
	if (result == -1)
		return (result);
	if ((result == 0 && *prev_result == 0)
		|| (result == 0 && *prev_result == -1))
		ft_putstr_out("\n");
	if (argc > 4 && result == 0)
		print_head(arg);
	ft_putstr_out(buff + (total_buff_size(arg, byte_size, 1) - byte_size));
	free(buff);
	*prev_result = result;
	return (0);
}
