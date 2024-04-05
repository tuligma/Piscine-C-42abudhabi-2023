/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 03:51:01 by npentini          #+#    #+#             */
/*   Updated: 2024/04/05 07:16:46 by npentini         ###   ########.fr       */
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

void	convert(int nbr, char *base, char *result, int state)
{
	int	len;
	int	i;

	i = 0;
	if (nbr == 0)
		result[i++] = '0';
	len = ft_strlen(base);
	while (nbr)
	{
		result[i++] = base[(nbr % len)];
		nbr /= len;
	}
	if (state == -1)
		result[i++] = '-';
	result[i] = '\0';
	len = ft_strlen(result);
	i = 0;
	while (len--)
		write(1, &result[len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	result[100];
	int		i;
	int		state;

	if (!(checker(base)))
	{
		state = 1;
		i = 0;
		while (i < (int) sizeof(result))
			result[i++] = '\0';
		if (nbr < 0)
		{
			state = -1;
			nbr *= -1;
		}
		convert(nbr, base, result, state);
	}
}
