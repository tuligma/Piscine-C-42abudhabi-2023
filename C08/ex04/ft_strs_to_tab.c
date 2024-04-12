/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:31:33 by npentini          #+#    #+#             */
/*   Updated: 2024/04/12 22:06:20 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;
	int		size;

	size = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_str_to_tab(int ac, char **av)
{
	t_stock_str	*array;
	int			x;

	array = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (array == NULL)
		return (NULL);
	x = -1;
	while (++x < ac)
	{
		array[x].size = ft_strlen(av[x]);
		array[x].str = av[x];
		array[x].copy = ft_strdup(av[x]);
		if (array[x].copy == NULL)
		{
			while (x >= 0)
				free(array[x--].copy);
			free(array);
			return (NULL);
		}
	}
	array[x].str = NULL;
	return (array);
}
