/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:27 by npentini          #+#    #+#             */
/*   Updated: 2024/05/14 00:23:36 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strdup(char *src, int size)
{
	char	*dest;
	int		i;
	
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < size)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

int	ones(char *str, h_list **table)
{
	t_list *current;
	int		j;

	j = 0;
	current = table[j]->list;
	while (current != NULL && (str[j] - '0') != ft_atoi(current->key))
		current = current->next;
	if (current == NULL)
		return (2);
	ft_putstr_fd(current->value, STDOUT_FILENO);
	return (0);
}

int	hundreds_up(char *str, h_list **table, int len)
{
	t_list *current;
	int j;
	int num;

	j = 0;
	while (table[j] != NULL && table[j]->len != len)
		j++;
	if (table[j] == NULL)
		return (2);
	current = table[j]->list;
	num = ft_atoi(str);
	num -= (num % 100);
	while (current->next != NULL && ft_atoi(current->key) != num)
		current = current->next;
	if (current == NULL)
		return (2);
	ft_putstr_fd(current->value, STDOUT_FILENO);
	return (0);
}

int	tens(char *str, h_list **table)
{
	t_list *current;
	int		j;
	int		num;
	
	j = 0;
	num = ft_atoi(str);
	if (num >= 11 && num <= 19)
		j = 1;
	else 
		j = 2;
	if (num / 10 > 1 && num % 10 != 0)
		num -= (num % 10);
	current = table[j]->list;
	while (current != NULL && num != ft_atoi(current->key))
		current = current->next;
	if (current == NULL)
		return (2);
	ft_putstr_fd(current->value, STDOUT_FILENO);
	num = ft_atoi(str);
	if (num / 10 > 1 && ft_atoi(str) % 10 != 0)
	{	
		ft_putchar_fd(' ', STDOUT_FILENO);
		num = ones(str + 1, table);
		if (num != 0)
			return (2);
	}	
	return (0);
}

int	order_magnitude(h_list **table, int len)
{
	int	x;

	x = -1;
	while (table[++x] != NULL && table[x]->len != len)
	{
		if (table[x]->len > len)
			break;
	}
	if (table[x] == NULL)
		return (2);
	if (table[x]->len > len)
		x -= 1;
	ft_putstr_fd(table[x]->list->value, STDOUT_FILENO);
	return (0);
}

int search_per_order(char *str, h_list **table, int len, int full_len)
{
	int	result;
	int	x;

	x = 0;
	while (len > 0 && str[x] != '\0')
	{
		if (len == 1)
		{
			result = ones(str + x, table);
			if (result == 2)
				return (result);
			if (full_len - len > 0 )
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
			if (full_len > 0)
				ft_putchar_fd(' ', STDOUT_FILENO);
			len--;
		}
		x++;
	}
	return (0);
}

int	search_arg1(char *str, h_list **table)
{
	char *substr;
	int	len;
	int	offset_len;
	int	result;
	int	x;

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

int	main(int argc, char *argv[])
{
	int		status;
	h_list **table;

	status = error_handler(argc, argv);
	if (status != 0)
		return (print_error(status));
	table = extract_create(argc, argv);
	if (table == NULL)
		return (print_error(status));
	status = search_arg1(argv[1], table);
	if (status != 0)
	{
		free_table(table, NULL);
		return (print_error(status));
	}
	free_table(table, NULL);
	return (0);
}