/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 03:27:58 by npentini          #+#    #+#             */
/*   Updated: 2024/04/20 03:28:01 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	total_buff_size(char *arg, int byte_size, int buff_size)
{
	char	*buff;
	int		count;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (fd);
	count = 0;
	while (buff_size != 0)
	{
		count += buff_size;
		buff = (char *)malloc(sizeof(char) * byte_size);
		if (buff == NULL)
			return (12);
		buff_size = read(fd, buff, byte_size);
		if (buff_size == -1)
			return (buff_size);
		free(buff);
	}
	close(fd);
	return (count - 1);
}

int	read_print(char *buff, char *arg, int buff_size)
{
	int		fd;
	int		buff_read;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (fd);
	buff_read = read(fd, buff, buff_size);
	if (buff_read == -1)
		return (buff_read);
	buff[buff_read] = '\0';
	close(fd);
	return (0);
}

int	execute_read(char *arg, int byte_size, char **buff)
{
	int		buff_size;
	int		result;

	buff_size = total_buff_size(arg, byte_size, 1);
	if (buff_size == -1)
		return (buff_size);
	if (byte_size > buff_size)
		byte_size = buff_size;
	*buff = (char *)malloc(sizeof(char) * buff_size + 1);
	if (*buff == NULL)
		return (12);
	result = read_print(*buff, arg, buff_size);
	if (result == -1)
		return (result);
	return (result);
}

int	ft_tail(int argc, char *argv[], int byte_size, int fail)
{
	int		result;
	int		i;
	int		prev_result;

	i = 2;
	prev_result = 0;
	while (++i < argc)
	{
		if (i > 3 && argc > 4)
		{
			result = print_multi_out(argv[i], byte_size, &prev_result, argc);
			if (result == -1)
				fail = print_error(argv[i], errno);
			prev_result = result;
		}
		else
		{
			result = print_single_out(argv[i], byte_size, &prev_result, argc);
			if (result == -1)
				fail = print_error(argv[i], errno);
			prev_result = result;
		}
	}
	return (fail);
}
