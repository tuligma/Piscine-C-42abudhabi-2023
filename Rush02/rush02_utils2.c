/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 04:12:21 by npentini          #+#    #+#             */
/*   Updated: 2024/05/14 00:33:07 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	table_size(char *str)
{
	int		size;
	int		x;
	int		j;
	int		old;
	int		new;

	x = 0;
	j = 0;
	old = 0;
	size = 0;
	while (str[x] != '\0')
	{
		if (str[x] != '\n')
			x++;
		else
		{
			new = key_size(str + j, x - j);
			if (new != old)
			{
				size++;
				old = new;
			}
			x++;
			j = x;
		}
	}
	return (size);
}

void	*free_table(h_list **table, char *str)
{
	t_list	*current;
	t_list	*temp;
	int		x;

	x = -1;
	while (table[++x] != NULL)
	{
		current = table[x]->list;
		while (current != NULL)
		{
			temp = current;
			current = current->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
		free(table[x]);
	}
	free(table);
	if (str != NULL)
		free(str);
	table = NULL;
	return (NULL);
}

void	*free_error(char **arr, int i)
{
	while (--i > 0)
		free(arr[i]);
	free(arr);
	arr = NULL;
	return (NULL);
}

h_list	**table_creation(int size)
{
	h_list	**table;
	int		x;

	table = (h_list **)malloc(sizeof(h_list) * (size + 2));
	if (table == NULL)
		return (NULL);
	x = -1;
	while (++x < size + 1)
	{
		table[x] = (h_list *)malloc(sizeof(h_list));
		if (table[x] == NULL)
			return (free_table(table, NULL));
		table[x]->list = NULL;
	}
	table[x] = NULL;
	return (table);
}
