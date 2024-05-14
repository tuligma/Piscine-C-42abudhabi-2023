/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 02:22:00 by npentini          #+#    #+#             */
/*   Updated: 2024/05/14 04:06:25 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	order_magnitude(h_list **table, int len)
{
	int	x;

	x = -1;
	while (table[++x] != NULL && table[x]->len != len)
	{
		if (table[x]->len > len)
			break ;
	}
	if (table[x] == NULL)
		return (2);
	if (table[x]->len > len)
		x -= 1;
	ft_putstr_fd(table[x]->list->value, STDOUT_FILENO);
	return (0);
}

int	search_per_order(char *str, h_list **table, int len, int full_len)
{
	int	result;
	int	x;

	x = 0;
	while (str[x] != '\0' && str[x] == '0')
	{
		x++;
		len--;
	}
	while (len > 0 && str[x] != '\0')
	{
		if (len == 1)
		{
			result = ones(str + x, table);
			if (result == 2)
				return (result);
			if (full_len - len > 0)
				ft_putchar_fd(' ', STDOUT_FILENO);
			len--;
		}
		else if (len == 2)
		{
			result = tens(str + x, table);
			if (result == 2)
				return (result);
			if (len < full_len - 1)
				ft_putchar_fd(' ', STDOUT_FILENO);
			len -= 2;
		}
		else if (len == 3)
		{
			result = ones(str, table);
			if (result != 0)
				return (2);
			ft_putchar_fd(' ', STDOUT_FILENO);
			result = hundreds_up(str + x, table, len);
			if (result == 2)
				return (result);
			len--;
			if (ft_atoi(str + (x + 1)) == 0)
				break ;
			else
				ft_putchar_fd(' ', STDOUT_FILENO);
		}
		x++;
	}
	return (0);
}

int	search_arg1(char *str, h_list **table)
{
	char	*substr;
	int		len;
	int		offset_len;
	int		result;
	int		x;

	len = ft_strlen(str);
	x = 0;
	while (str[x] != '\0' && str[x] == '0' && len > 1)
	{
		x++;
		len--;
	}
	while (len > 0)
	{
		if (len % 3 == 0)
			offset_len = 3;
		else
			offset_len = len % 3;
		substr = ft_strdup(str + x, offset_len);
		if (substr == NULL)
			return (2);
		result = search_per_order(substr, table, offset_len, len);
		if (result == 2)
			return (result);
		if (len > 3)
		{
			result = order_magnitude(table, len);
			if (result == 2)
				return (result);
		}
		x += offset_len;
		if (ft_atoi(str + x) != 0)
			ft_putchar_fd(' ', STDOUT_FILENO);
		len -= offset_len;
		free(substr);
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
