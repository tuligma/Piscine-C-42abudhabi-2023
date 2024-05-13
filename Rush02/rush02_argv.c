/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:38:50 by npentini          #+#    #+#             */
/*   Updated: 2024/05/13 23:58:57 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

int	ft_isdigit(char *str)
{
	int	x;

	x = -1;
	while (str[++x] != '\0')
	{
		if (str[x] < '0' || str[x] > '9')
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
	if (argc < 2 || argc > 3)
		return (1);
	if (argc == 2 && ft_isdigit(argv[1]) != 0)
		return (2);
	if (argc == 3 && ft_isdigit(argv[2]) != 0)
		return (2);
	return (0);
}
