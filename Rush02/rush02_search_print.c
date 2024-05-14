/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_search_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 02:23:56 by npentini          #+#    #+#             */
/*   Updated: 2024/05/14 03:46:27 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ones(char *str, h_list **table)
{
	t_list	*current;
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
	t_list	*current;
	int		j;
	int		num;

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

int	tens_ones(char *str, h_list **table)
{
	int	num;

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

int	tens(char *str, h_list **table)
{
	t_list	*current;
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
	num = tens_ones(str, table);
	if (num != 0)
		return (2);
	return (0);
}
