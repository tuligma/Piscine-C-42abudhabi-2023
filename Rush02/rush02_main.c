/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:27 by npentini          #+#    #+#             */
/*   Updated: 2024/05/11 13:57:14 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

int	ones(char *str, h_list **table, int x, int len)
{
	t_list *current;
	int		j;

	j = 0;
	current = table[j]->list;
	while (current != NULL && (str[x] - '0') != ft_atoi(current->key))
		current = current->next;
	if (current == NULL)
		return (2);
	ft_putstr_fd(current->value, STDOUT_FILENO);
	if (len > 2)
		ft_putchar_fd(' ', STDOUT_FILENO);
	return (0);
}

int	hundreds_up(char *str, h_list **table, int x, int len)
{
	t_list *current;
	int j;
	int	result;

	result = ones(str, table, x, len);
	if (result != 0)
		return(result);
	j = 0;
	while (table[j] != NULL && table[j]->len != len)
		j++;
	current = table[j]->list;
	while (current->next != NULL && ft_strcmp(str, current->key) != 0)
		current = current->next;
	if (current == NULL)
		return (2);
	ft_putstr_fd(current->value, STDOUT_FILENO);
	if (len > 2 && ft_atoi(str) % ft_atoi(current->key) != 0)
		ft_putchar_fd(' ', STDOUT_FILENO);
	return (0);
}

int	tens(char *str, h_list **table, int x, int len)
{
	t_list *current;
	int		j;
	int		num;
	
	j = 0;
	num = ft_atoi(str + x);
	if (num >= 11 && num <= 19)
		j = 1;
	else 
		j = 2;
	if (num / 10 > 1 && ft_atoi(str + x) % 10 != 0)
		num -= (num % 10);
	current = table[j]->list;
	while (current != NULL && num != ft_atoi(current->key))
		current = current->next;
	if (current == NULL)
		return (2);
	ft_putstr_fd(current->value, STDOUT_FILENO);
	num = ft_atoi(str + x);
	if (num / 10 > 1 && ft_atoi(str + x) % 10 != 0)
	{	
		ft_putchar_fd(' ', STDOUT_FILENO);
		num = ones(str, table, ++x, len);
		if (num != 0)
			return (2);
	}	
	return (0);
}

int	search_arg1(char *str, h_list **table)
{
	int	len;
	int	x;
	int result;

	len = ft_strlen(str);
	x = -1;
	while (str[++x] != '\0' && len > 0)
	{
		if (str[x] - '0' == 0)
		{
			len--;
			continue;
		}
		if (len == 1)
		{
			result = ones(str, table, x, len);
			if (result != 0)
				return (result);
			len--;
		}
		if (len == 2)
		{
			result = tens(str, table, x, len);
			if (result != 0)
				return (result);
			len -= 2;
		}
		if (len > 2 && (str[x] - '0') != 0)
		{
			result = hundreds_up(str, table, x, len);
			if (result != 0)
				return (result);
			len--;
		}
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