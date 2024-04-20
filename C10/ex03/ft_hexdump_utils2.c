/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:18:02 by npentini          #+#    #+#             */
/*   Updated: 2024/04/21 02:05:23 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	off_set_byte(int j)
{
	char	*buff;
	int		i;

	i = 8;
	buff = (char *)malloc(sizeof(char) * (i + 1));
	if (buff == NULL)
		return (12);
	buff[i] = '\0';
	while (--i)
		buff[i] = 0;
	i = 8;
	while (i)
	{
		buff[--i] = '0' + (j % 16);
		j /= 16;
	}
	ft_putstr_out(buff);
	free(buff);
	return (0);
}

int	open_read(char *arg, char **buffer, int arg_size, int total_size)
{
	char 	*buff;
	int		fd;
	int		count_read;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (fd);
	buff = (char *)malloc(sizeof(char *) * arg_size);
	if (buffer == NULL)
		return (12);
	count_read = read(fd, buff, arg_size);
	if (count_read == -1)
		return (count_read);
	buff[arg_size] = '\0';
	ft_strlcat(*buffer, buff, total_size);
	free(buff);
	close(fd);
	return (0);
}

int	buffer_extraction(int argc, char *argv[], char **buffer, int total_size)
{
	int		i;
	int		status;
	int		arg_size;
	int		result;

	i = 1;
	status = 0;
	while (++i < argc)
	{
		arg_size = total_buffer_size(argv[i], 1);
		if (arg_size == -1 || arg_size == 12)
		{
			status = print_error(argv[i], errno);
			continue ;
		}
		result = open_read(argv[i], buffer, arg_size, total_size);
		if ( result == -1 || result == 12)
		{
			status = print_error(argv[i], errno);
			continue ;
		}
		
	}
	return (status);
}