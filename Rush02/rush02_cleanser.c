/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_cleanser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:16:47 by npentini          #+#    #+#             */
/*   Updated: 2024/05/16 23:23:54 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	cleanse_size(char *str)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (str[x] != '\0')
	{
		while ((str[x] >= 9 && str[x] <= 13) || str[x] == ' ' || str[x] == '\n')
			x++;
		while (str[x] != '\0' && str[x] != '\n')
		{
			count++;
			x++;
		}
		if (str[x] == '\n')
		{
			count++;
			x++;
		}
	}
	return (count);
}

char	*cleanse_dict(char *str)
{
	char	*new_str;
	int		x;
	int		i;
	int		size;

	size = cleanse_size(str);
	new_str = (char *)malloc(sizeof(char) * (size + 1));
	if (new_str == NULL)
		return (NULL);
	x = 0;
	i = 0;
	while (str[x] != '\0')
	{
		while ((str[x] >= 9 && str[x] <= 13) || str[x] == ' ' || str[x] == '\n')
			x++;
		while (str[x] != '\0' && str[x] != '\n')
			new_str[i++] = str[x++];
		if (str[x] == '\n')
			new_str[i++] = str[x++];
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}
