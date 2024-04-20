/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:42:57 by npentini          #+#    #+#             */
/*   Updated: 2024/04/20 13:47:54 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	error_handler(int argc, char *argv[])
{
	if (argc == 1 || (argc <= 2 && argv[1][0] == '-' && argv[1][1] == 'C'))
	{
		while (1)
			continue ;
	}
	if (argv[1][0] == '-' && argv[1][1] != 'C')
		return (print_error_arg(argv[1]));
	return (1);
}
