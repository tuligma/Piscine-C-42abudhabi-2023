/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:25:03 by npentini          #+#    #+#             */
/*   Updated: 2024/04/24 00:53:18 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	error_handler(int argc, char *argv[])
{
	if (argc == 1 || (argc <= 2 && argv[1][0] == '-' && argv[1][1] == 'C'))
	{
		while (1)
			continue ;
	}
	if (argv[1][0] == '-' && argv[1][1] != 'C')
		return (print_error_flag(argv[1]));
	return (0);
}

int	off_set_byte(int j)
{
	char	*buff;
	int		i;
	int		x;

	i = 8;
	buff = (char *)malloc(sizeof(char) * (i + 1));
	if (buff == NULL)
		return (12);
	buff[i] = '\0';
	while (--i)
		buff[i] = 'a';
	i = 8;
	x = 0;
	while (i)
	{
		x = j % 16;
		if (x < 10)
			buff[--i] = '0' + x;
		else
			buff[--i] = 'a' + (x - 10);
		j /= 16;
	}
	ft_putstr_fd(buff, STDOUT_FILENO);
	free(buff);
	return (0);
}

int	arg_size(char *arg, int buff_size)
{
	char	*buff;
	int		fd;
	int		size;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (fd);
	size = 0;
	while (buff_size != 0)
	{
		size += buff_size;
		buff = (char *)malloc(sizeof(char) * 16);
		if (buff == NULL)
			return (12);
		buff_size = read(fd, buff, 16);
		if (buff_size == -1)
			return (buff_size);
		free(buff);
	}
	close(fd);
	return (size - 1);
}

int	total_size(int argc, char *argv[])
{
	int	count;
	int	size;
	int	i;

	count = 0;
	i = 1;
	while (++i < argc)
	{
		size = arg_size(argv[i], 1);
		if (size == -1 || size == 12)
			continue ;
		count += size;
	}
	return (count);
}

int	arg_size_offset(char *arg, char *buffer, int buffer_size)
{
	int		fd;
	int		offset_buffer_size;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (-1);
	}
	offset_buffer_size = 16 - buffer_size;
	buffer_size = read(fd, buffer + buffer_size, offset_buffer_size);
	if (buffer_size == -1)
	{
		free(buffer);
		return (-1);
	}
	close(fd);
	return (offset_buffer_size);
}
