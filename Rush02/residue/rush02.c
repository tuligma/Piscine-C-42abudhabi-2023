/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:29:43 by npentini          #+#    #+#             */
/*   Updated: 2024/05/14 02:46:28 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_list	*ft_create_elem(char *key, char *value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}

int	insert_htable(h_list **table, char *key, char *value, int key_len)
{
	t_list	*node;
	t_list	*current;
	int		x;
	int		index;

	if (key == NULL || value == NULL || key_len == 0)
		return (-1);
	node = ft_create_elem(key, value);
	if (node == NULL)
		return (-1);
	index = key_len;
	if (index == 1)
		index -= 1;
	else if (index == 2 && (ft_atoi(key) >= 11 && ft_atoi(key) <= 19))
		index -= 1;
	else if (index > 4)
	{
		x = 0;
		while (table[x]->list != NULL)
			x++;
		index = x;
	}
	table[index]->len = key_len;
	if (table[index]->list == NULL)
		table[index]->list = node;
	else
	{
		current = table[index]->list;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
	return (0);
}

int	data_processing(h_list **table, char *str)
{
	char	*key;
	char	*value;
	int		x;
	int		j;
	int		result;

	x = 0;
	j = 0;
	while (str[x] != '\0')
	{
		if (str[x] != '\n')
			x++;
		else
		{
			key = key_extraction(str + j, x - j);
			value = value_extraction(str + j, x - j);
			result = insert_htable(table, key, value, key_size(str + j, x - j));
			if (result == -1)
				return (-1);
			x++;
			j = x;
		}
	}
	return (0);
}