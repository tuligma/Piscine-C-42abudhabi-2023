/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:06:04 by npentini          #+#    #+#             */
/*   Updated: 2024/04/25 23:07:39 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	read_arg(int fd, char **buff)
{
	int	buff_size;

	*buff = (char *)malloc(sizeof(char) * 16);
	if (buff == NULL)
		return (12);
	buff_size = read(fd, *buff, 16);
	return (buff_size);
}

int	buff_extraction(int argc, char *argv[], int *offset_ptr)
{
	char	*buff;
	int		fd;
	int		buff_size;
	int		i;
	int		x;

	x = 1;
	while (++x < argc)
	{
		fd = open_arg(argv[x], offset_ptr);
		if (fd == -1)
			return (fd);
		buff_size = 1;
		i = 0;
		while (buff_size > 0)
		{
			buff_size = read_arg(fd, &buff);
			if (buff_size == -1)
				return (buff_size);
			if ((argc > 3 && x + 1 <= argc - 1)
				&& (buff_size > 0 && buff_size < 16))
				*offset_ptr = buff_offset(argv[x + 1], &buff, buff_size);
			buff_size = print_all(buff, buff_size, *offset_ptr, i);
			if (buff_size == -1)
				return (12);
			i += buff_size;
		}
		free(buff);
		close(fd);
	}
	return (i);
}

// int	ft_hexdump(int argc, char *argv[], int status)
// {
// 	int	size;
// 	int	i;
// 	int	result;
// 	int	x;
// 	int	offset_ptr;

// 	size = total_size(argc, argv);
// 	if (size == -1 || size == 12)
// 		return (print_error(argv[2], errno));
// 	i = 0;
// 	x = 1;
// 	offset_ptr = 0;
// 	while (i < size)
// 	{
// 		result = buff_extraction(argc, argv, ++x, &offset_ptr);
// 		if (result == -1 || result == 12)
// 			status = print_error(argv[x], errno);
// 		i += result;
// 	}
// 	if (i == size)
// 	{
// 		result = off_set_byte(i);
// 		if (result == -1)
// 			status = print_error(argv[x], errno);
// 		ft_putchar_fd('\n', STDOUT_FILENO);
// 	}
// 	return (status);
// }

int	main(int argc, char *argv[])
{
	int	status;
	int	offset_ptr;

	status = error_handler(argc, argv);
	if (status == 1)
		return (status);
	offset_ptr = 0;
	status = buff_extraction(argc, argv, &offset_ptr);
	if (status == 1)
		return (status);
	// status = ft_hexdump(argc, argv, 0);
	// if (status == 1)
	// 	return (status);
	return (0);
}
