/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:27 by npentini          #+#    #+#             */
/*   Updated: 2024/05/15 04:03:04 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

h_list	**extract_create(int argc, char *argv[])
{
	h_list	**table;
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
	free(dict);
	return (table);
}



int	zero_arg(char *str, h_list **table)
{
	int	len;
	int	x;
	int	result;

	len = ft_strlen(str);
	x = 0;
	while (str[x] != '\0' && str[x] == '0')
		x++;
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
		return (2);
	return (0);
	
}

int	main(int argc, char *argv[])
{
	h_list	**table;
	char	*str;
	int		status;

	status = error_handler(argc, argv);
	if (status != 0)
		return (print_error(status));
	table = extract_create(argc, argv);
	if (table == NULL)
		return (print_error(status));
	if (argc == 2)
		str = argv[1];
	else
		str = argv[2];
	status = zero_arg(str, table);
	if (status != 0)
	{
		free_table(table, NULL);
		if (status == 1)
			return (0);
		else
			return (print_error(status));
	}	
	status = search_arg1(str, table);
	if (status != 0)
	{
		free_table(table, NULL);
		return (print_error(status));
	}
	free_table(table, NULL);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
