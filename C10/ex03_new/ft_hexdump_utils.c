/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:22:41 by npentini          #+#    #+#             */
/*   Updated: 2024/04/24 03:00:13 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(fd, &str[i++], 1);
}

int	buff_offset(char *arg, char **buff, int buff_size)
{
	int		fd;
	int		offset_buff_size;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (fd + print_error(arg, errno));
	offset_buff_size = 16 - buff_size;
	buff_size = read(fd, *buff + buff_size, offset_buff_size);
	if (buff_size == -1)
		return (buff_size + print_error(arg, errno));
	close(fd);
	return (offset_buff_size);
}

int	offset_pointer(int fd, int *offset_ptr)
{
	char	*buff;
	int		buff_size;

	buff = (char *)malloc(sizeof(char) * (*offset_ptr));
	if (buff == NULL)
		return (-1);
	buff_size = read(fd, buff, *offset_ptr);
	if (buff_size == -1)
		return (-1);
	if (buff_size == *offset_ptr)
		*offset_ptr = 0;
	free(buff);
	return (fd);
}

int	open_arg(char *arg, int *offset_ptr)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (*offset_ptr > 0)
		fd = offset_pointer(fd, offset_ptr);
	return (fd);
}
