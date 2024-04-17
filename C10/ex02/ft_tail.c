/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:42:40 by npentini          #+#    #+#             */
/*   Updated: 2024/04/17 05:32:19 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_tail(int argc, char *argv[], int byte_size)
{
	int		success;
	int		fail;
	int		i;
	int		x;

	i = 2;
	fail = 0;
	x = 0;
	while (++i < argc)
	{
		success = execute_read(argc, argv[i], byte_size);
		if (success == -1)
		{
			fail = print_error(argv[i], errno);
			x = 1;
		}
		else
		{
			if (i < argc - 1 && x == 0)
				ft_putstr_out("\n");
		}
	}
	return (fail);
}

int	main(int argc, char *argv[])
{
	int		byte_size;

	if (argc > 3)
	{
		if (ft_isdigit(argv[2]))
			return (print_error_byte(argv[2]));
		if (argv[1][0] == '-' && argv[1][1] != 'c')
			return (print_error_byte(argv[1]));
		byte_size = ft_atoi(argv[2]);
		return (ft_tail(argc, argv, byte_size));
	}
	return (1);
}
