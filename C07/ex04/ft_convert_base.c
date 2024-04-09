/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:48:24 by npentini          #+#    #+#             */
/*   Updated: 2024/04/10 01:09:38 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_strlen(char *str);

int	ft_numlen(long long int n, char *base)
{
	int	len;
	int	len_base;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		len++;
		n *= -1;
	}
	len_base = ft_strlen(base);
	while (n > 0)
	{
		n /= len_base;
		len++;
	}
	return (len);
}

char	*conversion_base(long long int nbr, int len, char *base, char *str)
{
	int	len_base;

	str[len] = '\0';
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	else if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	len_base = ft_strlen(base);
	while (nbr > 0)
	{
		str[--len] = base[(nbr % len_base)];
		nbr /= len_base;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long int	bf;
	char			*new_base1;
	char			*new_base2;
	int				len;

	bf = ft_atoi_base(nbr, base_from);
	if (bf == -1)
		return (NULL);
	len = ft_numlen(bf, base_from);
	new_base1 = (char *)malloc(sizeof(char) * (len + 1));
	if (new_base1 == NULL)
		return (NULL);
	new_base1 = conversion_base(bf, len, base_from, new_base1);
	bf = ft_atoi_base(new_base1, base_from);
	free(new_base1);
	new_base1 = NULL;
	if (bf == -1)
		return (NULL);
	len = ft_numlen(bf, base_to);
	new_base2 = (char *)malloc(sizeof(char) * (len + 1));
	if (new_base2 == NULL)
		return (NULL);
	return (conversion_base(bf, len, base_to, new_base2));
}
