/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:04:48 by npentini          #+#    #+#             */
/*   Updated: 2024/04/17 04:52:17 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		++i;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i++] <= '9'))
			return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	x;
	int	state;
	int	result;

	x = 0;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == ' ' || str[x] == '\n')
		x++;
	state = 0;
	while (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			state++;
		x++;
	}
	result = 0;
	while (str[x] >= '0' && str[x] <= '9')
		result = result * 10 + (str[x++] - '0');
	if (state % 2)
		result *= -1;
	return (result);
}

int	total_buff_size(char *arg, int byte_size, int buff_size)
{
	char	*buff;
	int		count;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (fd);
	count = 0;
	buff = (char *)malloc(sizeof(char) * byte_size);
	if (buff == NULL)
		return (12);
	while (buff_size != 0)
	{
		count += buff_size;
		free(buff);
		buff = (char *)malloc(sizeof(char) * byte_size);
		if (buff == NULL)
			return (12);
		buff_size = read(fd, buff, byte_size);
		if (buff_size == -1)
			return (buff_size);
	}
	free(buff);
	close(fd);
	return (count - 1);
}

int	read_print(int argc, char *arg, int buff_size, int byte_size)
{
	char	*buff;
	int		fd;
	int		buff_read;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (fd);
	buff = (char *)malloc(sizeof(char) * buff_size + 1);
	if (buff == NULL)
		return (12);
	buff_read = read(fd, buff, buff_size);
	if (buff_read == -1)
		return (buff_read);
	buff[buff_read] = '\0';
	if (argc > 4)
		print_head(basename(arg));
	ft_putstr_out(buff + (buff_size - byte_size));
	free(buff);
	close(fd);
	return (0);
}

int	execute_read(int argc, char *arg, int byte_size)
{
	int		success;
	int		buff_size;

	if (byte_size < 0)
		byte_size *= -1;
	buff_size = total_buff_size(arg, byte_size, 1);
	if (buff_size == -1)
		return (buff_size);
	if (byte_size > buff_size)
		byte_size = buff_size;
	success = read_print(argc, arg, buff_size, byte_size);
	if (success == -1)
		return (success);
	return (0);
}
