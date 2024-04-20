/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 03:53:37 by npentini          #+#    #+#             */
/*   Updated: 2024/04/20 04:35:41 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	error_handler(int argc, char *argv[])
{
	if (argc == 1 || (argc == 3 && (argv[1][0] == '-' && argv[1][1] == 'c')
		&& !ft_isdigit(argv[2])))
	{
		while (1)
		{
			continue ;
		}
	}
	if (argc <= 3 && (argv[1][0] == '-' && argv[1][1] != 'c'))
		return (print_error_byte(argv[1]));
	if (argc <= 3 && !(argv[1][0] == '-' && argv[1][1] != 'c'))
		return (print_error_byte(argv[1]));
	if (argc <= 3 && (argv[1][0] == '-'
		&& argv[1][1] != 'c') && !ft_isdigit(argv[2]))
		return (print_error_byte(argv[2]));
	if (argc <= 3 && (argv[1][0] == '-'
		&& argv[1][1] == 'c') && ft_isdigit(argv[2]))
		return (print_error_byte(argv[2]));
	return (1);
}
