/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:28:21 by npentini          #+#    #+#             */
/*   Updated: 2024/05/14 00:36:16 by npentini         ###   ########.fr       */
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

int	line_count(char *str)
{
	int	x;
	int	count;

	x = -1;
	count = 0;
	while (str[++x] != '\0')
	{
		if (str[x] == '\n')
			count++;
	}
	return (count);
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
