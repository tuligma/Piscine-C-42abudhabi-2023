/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 02:22:00 by npentini          #+#    #+#             */
/*   Updated: 2024/05/15 04:16:13 by npentini         ###   ########.fr       */
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
		else if ((table[x] != NULL && table[x + 1] == NULL) && len > table[x]->len)
			break;
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
	while (len > 0 && str[x] != '\0')
	{
		if (str[x] == '0')
		{
			x++;
			len--;
			continue;
		}
		if (len == 1)
		{
			result = ones(str + x, table);
			if (result == 2)
				return (result);
			if (full_len - len > 0 && len > 1)
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
			if (ft_atoi(str + (x + 1)) == 0)
				break ;
			else
				ft_putchar_fd(' ', STDOUT_FILENO);
			len--;
		}
		x++;
	}
	return (0);
}

int zeros(char *str)
{
	int	x;
	
	x = 0;
	while (str[x] != '\0' && str[x] == '0')
		x++;
	return (x);
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
	while (str[x] != '\0' && str[x] == '0')
		x++;
	len -= x;
	if (len < 4)
	{
		result = search_per_order(str + x, table, len, len);
		if (result == 2)
			return (result);
		return (0);
	}
	else
	{
		while (len > 3)
		{
			if (len % 3 == 0)
				offset_len = 3;
			else
				offset_len = len % 3;
			substr = ft_strdup(str + x, offset_len);
			if (substr == NULL)
				return (2);
			search_arg1(substr, table);
			ft_putchar_fd(' ', STDOUT_FILENO);
			if (len > 3 && zeros(str + offset_len) != len)
			{
				result = order_magnitude(table, len);
				if (result == 2)
					return (result);
				
			}
			x += offset_len;
			len -= offset_len;
			free(substr);
			if (ft_atoi(str + x) * 1 != 0)
				ft_putchar_fd(' ', STDOUT_FILENO);
			offset_len = zeros(str + x);
			if (offset_len == len)
				break;
			
		}
		search_arg1(str + x, table);
	}
	return (0);
}
