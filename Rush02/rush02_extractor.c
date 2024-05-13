/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_extractor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:59:45 by npentini          #+#    #+#             */
/*   Updated: 2024/05/14 00:35:40 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*key_extraction(char *str, int size)
{
	char	*key;
	int		x;
	int		j;
	int		count;

	count = key_size(str, size);
	key = (char *)malloc(sizeof(char) * (count + 1));
	if (key == NULL)
		return (NULL);
	x = -1;
	j = 0;
	while ((str[++x] != '\0' && str[x] != ':') && x < size)
	{
		if (str[x] >= '0' && str[x] <= '9')
		{
			key[j] = str[x];
			j++;
		}
	}
	key[j] = '\0';
	return (key);
}

int	word_counter(char *str, int size)
{
	int	x;
	int	in_word;
	int	words;

	x = 0;
	in_word = 0;
	words = 0;
	while (str[x] != '\0' && str[x] != ':' && x < size)
		x++;
	x++;
	while (str[x] != '\0' && str[x] != '\n')
	{
		while ((str[x] >= 9 && str[x] <= 13) || str[x] == ' ')
			x++;
		if (in_word == 0)
		{
			in_word = 1;
			words++;
		}
		x++;
		if (str[x] == '\0' || str[x] == '\n' || str[x] == ' ')
			in_word = 0;
	}
	return (words);
}

int	value_size(char *str, int size)
{
	int		count;
	int		x;
	int		words;

	x = 0;
	count = 0;
	while (str[x] != '\0' && str[x] != ':')
		x++;
	while (str[++x] != '\0' && str[x] != '\n' && x < size)
	{
		if (str[x] != ' ' && str[x] != ':' && !(str[x] >= 9 && str[x] <= 13))
			count++;
	}
	words = word_counter(str, size);
	if (words >= 2)
		count += words - 1;
	return (count);
}

char	*value_extraction(char *str, int size)
{
	char	*value;
	int		x;
	int		j;
	int		count;

	count = value_size(str, size);
	value = (char *)malloc(sizeof(char) * (count + 1));
	if (value == NULL)
		return (NULL);
	x = 0;
	j = 0;
	while (str[x] != '\0' && str[x] != ':')
		x++;
	while (str[++x] != '\0' && str[x] != '\n' && x < size)
	{
		if (str[x] >= 9 && str[x] <= 13 && str[x] == ' ' && str[x] == ':')
			continue ;
		while (str[x] != '\0' && str[x] != '\n'
			&& !(str[x] >= 9 && str[x] <= 13) && str[x] != ' ')
		{
			value[j] = str[x];
			j++;
			x++;
		}
		if (word_counter(str, size) >= 2 && j > 0)
			value[j++] = ' ';
	}
	value[count] = '\0';
	return (value);
}
