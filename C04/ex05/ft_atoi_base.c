/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:15:03 by npentini          #+#    #+#             */
/*   Updated: 2024/04/05 23:26:31 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	checker(char *str)
{
	int	x;
	int	j;

	if (ft_strlen(str) <= 1)
		return (1);
	x = 0;
	while (str[x] != '\0')
	{
		if ((str[x] >= 9 && str[x] <= 13))
			return (1);
		j = 0;
		while (str[j] != '\0')
		{
			if ((str[j] == '-' || str[j] == '+')
				|| (str[x] == str[j] && x != j))
				return (1);
			j++;
		}
		x++;
	}
	return (0);
}

int	index_finder(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	if (base[i] == '\0')
		return (-1);
	return (0);
}

int	convert(char *str, char *base, int x, int state)
{
	int	result;
	int	len_base;

	result = 0;
	len_base = ft_strlen(base);
	while (str[x] != '\0')
	{
		if (index_finder(base, str[x]) == -1)
			return (0);
		result = result * len_base + index_finder(base, str[x]);
		x++;
	}
	if (state % 2)
		result *= -1;
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int		state;
	int		x;

	if (!(checker(base)))
	{
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
		return (convert(str, base, x, state));
	}
	return (0);
}
