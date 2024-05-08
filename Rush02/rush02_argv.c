/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:38:50 by npentini          #+#    #+#             */
/*   Updated: 2024/05/08 04:15:03 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_isdigit(char *str)
{
	int	x;

	x = -1;
	while (str[++x] != '\0')
	{
		if (str[x] < '0' && str[x] > '9')
			return (1);
	}
	return (0);
}

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

int	error_handler(int argc, char *argv[])
{
	int x;

	if (argc < 2)
		return(1);
	x = 0;
	while (++x < argc)
	{
		if (ft_isdigit(argv[x]) != 0 || ft_atoi(argv[x]) < 0)
			return (2);
	}
	return (0);
}