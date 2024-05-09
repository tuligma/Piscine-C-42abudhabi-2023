/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:27 by npentini          #+#    #+#             */
/*   Updated: 2024/05/10 03:20:11 by npentini         ###   ########.fr       */
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

	if (key == NULL || value == NULL || key_len == 0)
		return (-1);
	node = ft_create_elem(key, value);
	if (node == NULL)
		return (-1);
	if (key_len == 1)
		key_len -= 1;
	if (key_len == 2)
	{
		if (ft_atoi(key) >= 11 && ft_atoi(key) <= 19)
			key_len -= 1;
	}
	if (table[key_len]->list == NULL)
		table[key_len]->list = node;
	else
	{
		current = table[key_len]->list;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
	return (0);
}

int	data_processing(h_list **table, char *str)
{
	char *key;
	char *value;
	int	x;
	int	j;
	int	result;

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


void	print_table(h_list **table, int size)
{
	t_list *current;
	int	x;

	x = -1;
	while (++x < size)
	{
		printf("Bucket %d:\n", x + 1);
		current = table[x]->list;
		while (current != NULL)
		{
			printf("Key: %s	| Value %s\n", current->key, current->value);
			current = current->next;
		}
		printf("\n");
	}
}

int	extract_create(void)
{
	h_list 	**table;
	char	*dict;
	int		result;
	int		size;

	dict = NULL;
	result = dict_parse(&dict);
	if (result != 0)
		return (result);
	size = table_size(dict);
	table = table_creation(size);
	if (table == NULL)
		return (-1);
	result = data_processing(table, dict);
	if (result == -1)
		return (free_table(table, dict));
	print_table(table, size);
	free_table(table, dict);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		status;

	status = error_handler(argc, argv);
	if (status != 0)
		return (print_error(status));
	status = extract_create();
	if (status != 0)
		return (print_error(status));
	return (0);
}