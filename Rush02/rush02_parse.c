/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:50:34 by npentini          #+#    #+#             */
/*   Updated: 2024/05/14 02:11:47 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	filesize(char *file)
{
	char	*buff;
	int		fd;
	int		buff_size;
	int		count;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	buff_size = 1;
	count = 0;
	while (buff_size > 0)
	{
		count += buff_size;
		buff = (char *)malloc(sizeof(char) * 50);
		if (buff == NULL)
			return (-1);
		buff_size = read(fd, buff, 50);
		if (buff_size == -1)
			return (-1);
		free(buff);
	}
	close(fd);
	return (count);
}

int	dict_parse(char **buff, char *file)
{
	int		fd;
	int		buff_size;
	int		size;

	size = filesize(file);
	if (size == -1)
		return (2);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (2);
	*buff = (char *)malloc(sizeof(char) * size + 1);
	if (*buff == NULL)
		return (2);
	buff_size = read(fd, *buff, size);
	if (buff_size == -1)
		return (2);
	(*buff)[buff_size] = '\0';
	close(fd);
	return (0);
}

int	key_size(char *str, int size)
{
	int		count;
	int		x;

	x = -1;
	count = 0;
	while ((str[++x] != '\0' && str[x] != ':') && x < size)
	{
		if (str[x] >= '0' && str[x] <= '9')
			count++;
	}
	return (count);
}

int	table_size(char *str)
{
	int		size;
	int		x;
	int		j;
	int		old;
	int		new;

	x = 0;
	j = 0;
	old = 0;
	size = 0;
	while (str[x] != '\0')
	{
		if (str[x] != '\n')
			x++;
		else
		{
			new = key_size(str + j, x - j);
			if (new != old)
			{
				size++;
				old = new;
			}
			x++;
			j = x;
		}
	}
	return (size);
}