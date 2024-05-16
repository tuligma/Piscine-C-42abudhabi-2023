/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 02:22:00 by npentini          #+#    #+#             */
/*   Updated: 2024/05/16 23:35:44 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	order_magnitude(t_table **table, int len)
{
	int	x;

	x = -1;
	while (table[++x] != NULL && table[x]->len != len)
	{
		if (table[x]->len > len)
			break ;
		else if ((table[x] != NULL && table[x + 1] == NULL)
			&& len > table[x]->len)
			break ;
	}
	if (table[x] == NULL)
		return (2);
	if (table[x]->len > len)
		x -= 1;
	ft_putstr_fd(table[x]->list->value, STDOUT_FILENO);
	return (0);
}

int	search_per_order(char *str, t_table **table, int len, int full_len)
{
	int	result;
	int	x;

	x = 0;
	while (len > 0 && str[x] != '\0')
	{
		if (str[x] == '0')
		{
			x++;
			len--;
			continue ;
		}
		if (len == 1)
			result = handle_ones(str + x, table, &len, full_len);
		else if (len == 2)
			result = handle_tens(str + x, table, &len, full_len);
		else if (len == 3)
			result = handle_hundreds(str, table, &len, x);
		if (result == 1)
			break ;
		if (result == 2)
			return (result);
		x++;
	}
	return (0);
}

int	handle_thousands_up(char *str, t_table **table, int len, int *x)
{
	char	*substr;
	int		offset_len;
	int		result;

	if (len % 3 == 0)
		offset_len = 3;
	else
		offset_len = len % 3;
	substr = ft_strdup(str + *x, offset_len);
	if (substr == NULL)
		return (-1);
	search_arg1(substr, table);
	free(substr);
	ft_putchar_fd(' ', STDOUT_FILENO);
	if (len > 3 && zeros(str + offset_len) != len)
	{
		result = order_magnitude(table, len);
		if (result == 2)
			return (-1);
	}
	return (offset_len);
}

int	handle_large_number(char *str, t_table **table, int len, int *x)
{
	int		offset_len;
	int		count_zero;

	while (len > 3)
	{
		offset_len = handle_thousands_up(str, table, len, x);
		if (offset_len == -1)
			return (2);
		*x += offset_len;
		len -= offset_len;
		count_zero = zeros(str + *x);
		if (count_zero == len)
			break ;
		else
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	return (0);
}
