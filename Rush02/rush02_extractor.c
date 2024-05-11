/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_extractor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:59:45 by npentini          #+#    #+#             */
/*   Updated: 2024/05/11 05:08:22 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	line_count(char *str)
{
	int x;
	int	count;
	
	x = -1;
	count = 0;
	while (str[++x] != '\0')
	{
		if (str[x] == '\n')
			count++;
	}
	return (count);
}

char	*key_extraction(char *str, int size)
{
	char *key;
	int	x;
	int	j;
	int	count;
	
	count = key_size(str, size);
	key = (char *)malloc(sizeof(char) * (count + 1));
	if (key == NULL)
		return (NULL);
	x = -1;
	j = 0;
	while ((str[++x] != '\0' && str[x] != ':') && x < size)
	{
		if (str[x] >= '0' && str[x] <= '9')
		{
			key[j] = str[x];
			j++;
		}
	}
	key[j] = '\0';
	return (key);
}

void	*free_error(char **arr, int i)
{
	while (--i > 0)
		free(arr[i]);
	free(arr);
	arr = NULL;
	return (NULL);
}

int	word_counter(char *str, int size)
{
	int	x;
	int	in_word;
	int words;

	x = 0;
	in_word = 0;
	words = 0;
	while (str[x] != '\0' && str[x] != ':' && x < size)
		x++;
	x++;
	while (str[x] != '\0' && str[x] != '\n')
	{
		while ((str[x] >= 9 && str[x] <= 13) || str[x] == ' ')
			x++;
		if (in_word == 0)
		{
			in_word = 1;
			words++;
		}
		x++;
		if (str[x] == '\0' || str[x] == '\n' || str[x] == ' ')
			in_word = 0;
	}
	return (words);
}

int	value_size(char *str, int size)
{
	int		count;
	int		x;
	int		words;

	x = 0;
	count = 0;
	while (str[x] != '\0' && str[x] != ':')
		x++;
	while (str[++x] != '\0' && str[x] != '\n' && x < size)
	{
		if (str[x] != ' ' && str[x] != ':' && !(str[x] >= 9 && str[x] <= 13))
			count++;
	}
	words = word_counter(str, size);
	if (words >= 2)
		count += words - 1;
	return (count);
}

char	*value_extraction(char *str, int size)
{
	char *value;
	int	x;
	int	j;
	int	count;
	
	count = value_size(str, size);
	value = (char *)malloc(sizeof(char) * (count + 1));
	if (value == NULL)
		return (NULL);
	x = 0;
	j = 0;
	while (str[x] != '\0' && str[x] != ':')
		x++;
	while (str[++x] != '\0' && str[x] != '\n' && x < size)
	{
		if (str[x] >= 9 && str[x] <= 13 && str[x] == ' ' && str[x] == ':')
			continue;
		while(str[x] != '\0' && str[x] != '\n' && !(str[x] >= 9 && str[x] <= 13) && str[x] != ' ')
		{
			value[j] = str[x];
			j++;
			x++;
		}
		if (word_counter(str, size) >= 2 && j > 0)
			value[j++] = ' ';
	}
	value[count] = '\0';
	return (value);
}

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
	int	x;
	int	index;

	if (key == NULL || value == NULL || key_len == 0)
		return (-1);
	node = ft_create_elem(key, value);
	if (node == NULL)
		return (-1);
	index = key_len;
	if (index == 1)
	{
		index -= 1;
	}
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

h_list	**extract_create(int argc, char *argv[])
{
	h_list 	**table;
	char	*dict;
	int		result;
	int		size;
	char	*file;

	dict = NULL;
	if (argc == 3)
		file = argv[1];
	else
		file = "./numbers.dict";
	result = dict_parse(&dict, file);
	if (result != 0)
		return (NULL);
	size = table_size(dict);
	table = table_creation(size);
	if (table == NULL)
		return (NULL);
	result = data_processing(table, dict);
	if (result == -1)
		return (free_table(table, dict));
	// print_table(table, size);
	// free_table(table, dict);
	free(dict);
	return (table);
}

