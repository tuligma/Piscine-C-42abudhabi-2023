/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 01:27:20 by npentini          #+#    #+#             */
/*   Updated: 2024/05/16 02:46:18 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_table	**extract_create(int argc, char *argv[])
{
	t_table	**table;
	char	*dict;
	int		result;
	int		size;
	char	*file;

	dict = NULL;
	if (argc == 3)
		file = argv[1];
	else
		file = "numbers.dict";
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
	free(dict);
	return (table);
}

int	zeros(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0' && str[x] == '0')
		x++;
	return (x);
}

int	zero_arg(char *str, t_table **table)
{
	int	len;
	int	x;
	int	result;

	len = ft_strlen(str);
	x = zeros(str);
	if (len == 1 || len == x)
	{
		result = ones(str + len - 1, table);
		if (result == 2)
			return (result);
		ft_putchar_fd('\n', STDOUT_FILENO);
		return (1);
	}
	x = 0;
	while (table[x] != NULL && table[x + 1] != NULL)
		x++;
	if (len >= table[x]->len + 3)
		return (-1);
	return (0);
}

int	search_arg1(char *str, t_table **table)
{
	int		len;
	int		result;
	int		x;

	len = ft_strlen(str);
	x = zeros(str);
	len -= x;
	if (len < 4)
	{
		result = search_per_order(str + x, table, len, len);
		if (result == 2)
			return (result);
		return (0);
	}
	else
	{
		result = handle_large_number(str, table, len, &x);
		if (result == 2)
			return (result);
		search_arg1(str + x, table);
	}
	return (0);
}
