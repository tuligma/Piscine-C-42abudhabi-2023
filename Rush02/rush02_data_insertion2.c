/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_data_insertion2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 02:00:43 by npentini          #+#    #+#             */
/*   Updated: 2024/05/14 03:40:27 by npentini         ###   ########.fr       */
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

int	hash_index(h_list **table, char *key, int index)
{
	int	x;

	if (index == 1)
		return (0);
	else if (index == 2 && (ft_atoi(key) >= 11 && ft_atoi(key) <= 19))
		return (1);
	else if (index > 4)
	{
		x = 0;
		while (table[x]->list != NULL)
			x++;
		return (x);
	}
	return (index);
}

int	insert_htable(h_list **table, char *key, char *value, int key_len)
{
	t_list	*node;
	t_list	*current;
	int		index;

	if (key == NULL || value == NULL || key_len == 0)
		return (-1);
	node = ft_create_elem(key, value);
	if (node == NULL)
		return (-1);
	index = hash_index(table, key, key_len);
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
