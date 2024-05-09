/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 04:12:21 by npentini          #+#    #+#             */
/*   Updated: 2024/05/10 03:10:03 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	key_size(char *str, int size)
{
	int		count;
	int		x;

	x = -1;
	count = 0;
	while ((str[++x] != '\0' && str[x] != ':') && x < size)
	{
		if (str[x] >= '0' && str[x] <= '9')
			count++;
	}
	return (count);
}

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

int	free_table(h_list **table, char *str)
{
	t_list *current;
	t_list *temp;
	int	x;
	
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
	free(str);
	table = NULL;
	return (-1);
}

void free_arr(char **arr)
{
	int	x;

	x = -1;
	while (arr[++x] != NULL)
		free(arr[x]);
	free(arr);
	arr = NULL;
}

h_list	**table_creation(int size)
{
	h_list **table;
	int	x;

	table = (h_list **)malloc(sizeof(h_list) * (size + 1));
	if (table == NULL)
		return (NULL);
	x = -1;
	while (++x < size)
	{
		table[x] = (h_list *)malloc(sizeof(h_list));
		if (table[x] == NULL)
		{
			while (--x > 0)
				free(table[x]);
			free(table);
			return (NULL);
		}
		table[x]->list = NULL;
	}
	table[x] = NULL;
	return (table);
}