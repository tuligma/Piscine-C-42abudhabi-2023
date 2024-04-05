/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:15:03 by npentini          #+#    #+#             */
/*   Updated: 2024/04/05 07:43:39 by npentini         ###   ########.fr       */
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

int	convert(int nbr, char *base, int state)
{
	int	result;
	int	len;

	result = 0;
	if (nbr == 0)
		return (result);
	len = ft_strlen(base);
	while (nbr)
	{
		result = result * 10 + (base[(nbr % len)] - '0');
		nbr /= len;
	}
	if (state == -1)
		result *= -1;
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int		state;
	int		nbr;

	if (!(checker(base)))
	{
		nbr = ft_atoi(str);
		state = 1;
		if (nbr < 0)
		{
			state = -1;
			nbr *= -1;
		}
		return (convert(nbr, base, state));
	}
	return (0);
}
