/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_print_oth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 00:21:04 by npentini          #+#    #+#             */
/*   Updated: 2024/05/16 23:35:22 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	handle_ones(char *str, t_table **table, int *len, int full_len)
{
	int	result;

	result = ones(str, table);
	if (result == 2)
		return (result);
	if (full_len - *len > 0 && *len > 1)
		ft_putchar_fd(' ', STDOUT_FILENO);
	(*len)--;
	return (result);
}

int	handle_tens(char *str, t_table **table, int *len, int full_len)
{
	int	result;

	result = tens(str, table);
	if (result == 2)
		return (result);
	if (*len < full_len - 1)
		ft_putchar_fd(' ', STDOUT_FILENO);
	*len -= 2;
	return (result);
}

int	handle_hundreds(char *str, t_table **table, int *len, int x)
{
	int	result;

	result = ones(str, table);
	if (result != 0)
		return (2);
	ft_putchar_fd(' ', STDOUT_FILENO);
	result = hundreds_up(str + x, table, *len);
	if (result == 2)
		return (result);
	if (ft_atoi(str + (x + 1)) == 0)
		return (1);
	else
		ft_putchar_fd(' ', STDOUT_FILENO);
	(*len)--;
	return (result);
}
