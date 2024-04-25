/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 02:44:19 by npentini          #+#    #+#             */
/*   Updated: 2024/04/26 03:03:04 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	x;
	int	state;
	int	result;

	x = 0;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == ' ' || str[x] == '\n')
		x++;
	state = 0;
	while (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			state++;
		x++;
	}
	result = 0;
	while (str[x] >= '0' && str[x] <= '9')
		result = result * 10 + (str[x++] - '0');
	if (state % 2)
		result *= -1;
	return (result);
}

char	op(char *str)
{
	char *operator[5];
	int	x;
	int	len;

	operator[0][0] = '+';
	operator[1][0] = '-';
	operator[2][0] = '/';
	operator[3][0] = '*';
	operator[4][0] = '%';
	len = 5;
	x = -1;
	
}

void	do_op(int argc, char *argv[], char (*f)(char*))
{
	char	op;
	int	value1;
	int	value2;

	value1 = ft_atoi(argv[1]);
	value2 = ft_atoi(argv[3]);
}

int	main(int argc, char *argv[])
{

	if (argc == 4)
	{

		return (0);
	}
	return (1);
}