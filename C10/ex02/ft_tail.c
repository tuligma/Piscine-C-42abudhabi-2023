/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:42:40 by npentini          #+#    #+#             */
/*   Updated: 2024/04/20 03:24:26 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

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
		if (byte_size < 0)
			byte_size *= -1;
		return (ft_tail(argc, argv, byte_size, 0));
	}
	return (1);
}
