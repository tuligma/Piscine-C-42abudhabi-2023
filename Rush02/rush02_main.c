/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:27 by npentini          #+#    #+#             */
/*   Updated: 2024/05/09 02:59:48 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"



int	extract_create(void)
{
	h_list 	**table;
	char	*dict;
	char	**key;
	char	**value;
	int		result;
	int		size;
	int		x;

	dict = NULL;
	result = dict_parse(&dict);
	if (result != 0)
		return (result);
	size = table_size(dict);
	table = table_creation(size);
	if (table == NULL)
		return (-1);
	key = key_processing(dict);
	value = value_processing(dict);
	x = -1;
	while (value[++x] != NULL && key[x] != NULL)
		printf("%s: %s\n", key[x], value[x]);
	free_arr(value);
	free(dict);
	free_arr(key);
	free_table(table);
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