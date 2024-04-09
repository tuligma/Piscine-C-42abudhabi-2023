/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 01:14:44 by npentini          #+#    #+#             */
/*   Updated: 2024/04/10 02:57:20 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	array_size(char *str, char *charset)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i++] == charset[j] && charset[j] != '\0')
			j++;
		if (charset[j] == '\0')
				size++;
	}
	return (++size);
}

int	charset_skipper(char *charset, int x)
{
	while (charset[x] != '\0')
		x++;
	return (x);
}

int	ft_strlen(char *str, char *charset, int min)
{
	int	i;
	int	j;

	i = min;
	j = 0;
	while (str[i] != charset[j] && str[i] != '\0')
		i++;
	return (i - min);
}

char	*ft_strdup(char *str, char *charset, int min)
{
	char	*dest;
	int		size;
	int		i;

	size = ft_strlen(str, charset, min);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		dest[i] = str[min + i];
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		size;
	int		x;
	int		min;

	size = array_size(str, charset);
	array = (char **)malloc(sizeof(char *) * (size + 1));
	if (array == NULL)
		return (NULL);
	min = 0;
	x = 0;
	while (x < size)
	{
		array[x] = ft_strdup(str, charset, min);
		if (array[x] == NULL)
		{
			while (x != 0)
			{
				free(array[x--]);
				array[x] = NULL;
			}
			free(array);
			array = NULL;
			return (array);
		}
		min += ft_strlen(str, charset, min) + charset_skipper(charset, 0);
		x++;
	}
	array[x] = 0;
	return (array);
}
