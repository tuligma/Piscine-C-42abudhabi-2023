/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:25:21 by npentini          #+#    #+#             */
/*   Updated: 2024/05/06 05:35:50 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char *argv[])
{
	int		**arg;
	int		**table;

	if (argc < 2)
		return (print_error());
	if (ft_strcmp(argv[1], "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2") != 0)
		return (print_error());
	arg = arg_to_int(argv[1]);
	if (arg == NULL)
		return (print_error());
	table = rush01(arg);
	if (table == NULL)
		return (print_error());
	free_array(arg);
	free_array(table);
	return (0);
}
