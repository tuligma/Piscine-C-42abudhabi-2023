/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:06:04 by npentini          #+#    #+#             */
/*   Updated: 2024/04/24 01:15:12 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	buff_extraction(int argc, char *argv[], int x, int *offset_ptr, int *i)
{
	char	*buff;
	int		fd;
	int		buff_size;
	int		result;

	fd = open_arg(argv[x], offset_ptr);
	if (fd == -1)
		return (fd);
	buff_size = 1;
	while (buff_size > 0)
	{
		buff = (char *)malloc(sizeof(char) * 16);
		if (buff == NULL)
			return (12);
		buff_size = read(fd, buff, 16);
		if (buff_size == -1)
			return (buff_size);
		if (buff_size == 0)
			break ;
		if ((argc > 3 && x + 1 <= argc - 1)
			&& (buff_size > 0 && buff_size < 16))
		{
			*offset_ptr = buff_offset(argv[x + 1], &buff, buff_size);
			if (*offset_ptr == -1)
				*offset_ptr = 0;
		}
		result = off_set_byte(*i);
		if (result == 12)
			return (result);
		string_hex_print(buff, buff_size + (*offset_ptr));
		string_print(buff, buff_size + (*offset_ptr));
		ft_putchar_fd('\n', STDOUT_FILENO);
		free(buff);
		*i += buff_size + (*offset_ptr);
	}
	free(buff);
	close(fd);
	return (0);
}

int	ft_hexdump(int argc, char *argv[], int status)
{
	int	size;
	int	i;
	int	result;
	int	x;
	int	offset_ptr;

	size = total_size(argc, argv);
	if (size == -1 || size == 12)
		return (print_error(argv[2], errno));
	i = 0;
	x = 1;
	offset_ptr = 0;
	while (i < size)
	{
		result = buff_extraction(argc, argv, ++x, &offset_ptr, &i);
		if (result == -1 || result == 12)
			status = print_error(argv[x], errno);
	}
	if (i == size)
	{
		result = off_set_byte(i);
		if (result == -1)
			status = print_error(argv[x], errno);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	return (status);
}

int	main(int argc, char *argv[])
{
	int	status;

	status = error_handler(argc, argv);
	if (status == 1)
		return (status);
	status = ft_hexdump(argc, argv, 0);
	if (status == 1)
		return (status);
	return (0);
}
