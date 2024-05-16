/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:07:23 by npentini          #+#    #+#             */
/*   Updated: 2024/05/16 23:35:55 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	*free_table(t_table **table, char *str)
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

t_table	**table_creation(int size)
{
	t_table	**table;
	int		x;

	table = (t_table **)malloc(sizeof(t_table) * (size + 2));
	if (table == NULL)
		return (NULL);
	x = -1;
	while (++x < size + 1)
	{
		table[x] = (t_table *)malloc(sizeof(t_table));
		if (table[x] == NULL)
			return (free_table(table, NULL));
		table[x]->list = NULL;
	}
	table[x] = NULL;
	return (table);
}

int	data_processing(t_table **table, char *str)
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
