/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:58:05 by npentini          #+#    #+#             */
/*   Updated: 2024/04/13 01:58:07 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strchr(char *charset, char c)
{
	int	i;

	i = -1;
	while (charset[++i] != '\0')
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

int	array_size(char *str, char *charset)
{
	int	i;
	int	size;

	if (charset[0] == '\0')
		return (2);
	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\0' && !ft_strchr(charset, str[i]))
		{
			size++;
			while (str[i] != '\0' && !ft_strchr(charset, str[i]))
				i++;
		}
		else
			i++;
	}
	return (++size);
}

char	*ft_range(char *str, int min, int max)
{
	char	*dest;
	int		size;
	int		i;

	size = max - min;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		dest[i] = str[min + i];
	dest[i] = '\0';
	return (dest);
}

char	**free_me(char **array, int x)
{
	if (array[x] == NULL)
	{
		while (x >= 0)
		{
			free(array[x--]);
			array[x] = NULL;
		}
		free(array);
		array = NULL;
		return (array);
	}
	return (NULL);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		x;
	int		min;
	int		max;

	if (str == NULL || charset == NULL)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (array_size(str, charset) + 1));
	if (array == NULL)
		return (NULL);
	x = 0;
	max = 0;
	while (str[max] != '\0')
	{
		while (ft_strchr(charset, str[max]) && str[max] != '\0')
			max++;
		min = max;
		while (!ft_strchr(charset, str[max]) && str[max] != '\0')
			max++;
		array[x] = ft_range(str, min, max);
		if (array[x++] == NULL)
			return (free_me(array, x));
	}
	array[x] = (void *)0;
	return (array);
}
