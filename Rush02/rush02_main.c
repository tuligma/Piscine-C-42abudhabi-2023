/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:27 by npentini          #+#    #+#             */
/*   Updated: 2024/05/16 01:36:17 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char *argv[])
{
	t_table	**table;
	char	*str;
	int		status;

	status = error_handler(argc, argv);
	if (status != 0)
		return (print_error_free(status, NULL));
	table = extract_create(argc, argv);
	if (table == NULL)
		return (print_error_free(-1, NULL));
	if (argc == 2)
		str = argv[1];
	else
		str = argv[2];
	status = zero_arg(str, table);
	if (status != 0)
		return (print_error_free(status, table));
	status = search_arg1(str, table);
	if (status != 0)
		return (print_error_free(status, table));
	free_table(table, NULL);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
