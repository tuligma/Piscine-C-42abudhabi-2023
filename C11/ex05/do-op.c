/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 02:44:19 by npentini          #+#    #+#             */
/*   Updated: 2024/04/27 03:38:14 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	do_op(char op, int value1, int value2)
{
	int	(*operation[5])(int, int);
	int	i;

	operation[0] = addition;
	operation[1] = subtraction;
	operation[2] = division;
	operation[3] = multiplication;
	operation[4] = modulo;
	i = operator_validator(op);
	return (operation[i](value1, value2));
}

int	operator_validator(char c)
{
	int	operator[5];
	int	x;

	operator[0] = '+';
	operator[1] = '-';
	operator[2] = '/';
	operator[3] = '*';
	operator[4] = '%';
	x = -1;
	while (++x < 5)
	{
		if (operator[x] == c)
			return (x);
	}
	return (-1);
}

int	error_print(char *argv[])
{
	char	op;
	int		value2;
	int		result;

	result = 0;
	op = argv[2][0];
	value2 = ft_atoi(argv[3]);
	if (ft_strlen(argv[2]) != 1
		|| (ft_strlen(argv[2]) == 1 && operator_validator(op) == -1))
	{
		ft_putstr_fd("0\n", STDERR_FILENO);
		result = 1;
	}
	else if ((op == '%' && value2 == 0) || (op == '/' && value2 == 0))
	{
		if (op == '/')
			ft_putstr_fd("Stop: division by zero\n", STDERR_FILENO);
		else
			ft_putstr_fd("Stop: modulo by zero\n", STDERR_FILENO);
		result = 1;
	}
	return (result);
}

int	error_handler(int argc, char *argv[])
{
	int	result;

	result = 1;
	if (argc == 4)
	{
		while (--argc > 0)
		{
			if (argv[argc] == NULL)
				return (result);
		}
		result = error_print(argv);
		if (result == 1)
			return (result);
		return (0);
	}
	return (result);
}
