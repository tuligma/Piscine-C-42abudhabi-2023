/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:27 by npentini          #+#    #+#             */
/*   Updated: 2024/05/14 03:35:03 by npentini         ###   ########.fr       */
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
	print_table(table, size);
	free(dict);
	return (table);
}

int	main(int argc, char *argv[])
{
	h_list	**table;
	int		status;

	status = error_handler(argc, argv);
	if (status != 0)
		return (print_error(status));
	table = extract_create(argc, argv);
	if (table == NULL)
		return (print_error(status));
	status = search_arg1(argv[1], table);
	if (status != 0)
	{
		free_table(table, NULL);
		return (print_error(status));
	}
	free_table(table, NULL);
	return (0);
}
