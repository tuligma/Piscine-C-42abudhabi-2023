/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:27 by npentini          #+#    #+#             */
/*   Updated: 2024/05/08 04:30:38 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	fetching_parse(h_list**table)

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
	printf("%d\n", size);
	free(dict);
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