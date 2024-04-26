/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:14:35 by npentini          #+#    #+#             */
/*   Updated: 2024/04/27 02:52:01 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int argc, char *argv[])
{
	char	op;
	int		value1;
	int		value2;
	int		result;

	result = error_handler(argc, argv);
	if (result == 1)
		return (1);
	op = argv[2][0];
	value1 = ft_atoi(argv[1]);
	value2 = ft_atoi(argv[3]);
	result = do_op(op, value1, value2);
	ft_putnbr(result);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
