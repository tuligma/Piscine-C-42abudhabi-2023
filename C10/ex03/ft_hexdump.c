/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:45:13 by npentini          #+#    #+#             */
/*   Updated: 2024/04/21 01:52:30 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	string_process(char *argv[], char **buffer, int total_size)
{
	int	i;
	int	j;
	int	result;
	int	status;
	int	size;

	i = 1;
	j = 0;
	status = 0;
	while (j < total_size)
	{
		result = off_set_byte(j);
		if (result == 12)
		{
			status = print_error(argv[i++], result);
			continue ;
		}
		size = 16;
		if (j + size > total_size)
			size = (total_size - j);
		string_hex_print(*buffer + j, size);
		string_print(*buffer + j, size);
		ft_putstr_out("\n");
		j += 16;
	}
	if (j > total_size)
	{
		result = off_set_byte(j);
		if (result == 12)
			status = print_error(argv[i++], result);
		ft_putstr_out("\n");
	}
	return (status);
}

int	ft_hexdump(int argc, char *argv[], int total_size)
{
	char 	*buffer;
	int		count;
	int		result;
	int		status;
	int		i;
	
	i = 1;
	status = 0;
	while (++i < argc)
	{
		count = total_buffer_size(argv[i], 1);
		if (count == -1 || count == 12)
				continue ;
		total_size += count;
	}
	buffer = (char *)malloc(sizeof(char *) * (total_size + 1));
	if (buffer == NULL)
		return (print_error(argv[i], 12));
	buffer[0] = '\0';
	result = buffer_extraction(argc, argv, &buffer, total_size);
	if (result == -1)
		status = print_error(argv[1], errno);
	else if (result == 12)
		status = print_error(argv[1], 12);
	result = string_process(argv, &buffer, total_size);
	free(buffer);
	return (status);
}

int	main(int argc, char *argv[])
{
	if (argc > 2)
	{
		if (argv[1][0] == '-' && argv[1][1] != 'C')
			return (print_error_arg(argv[1]));
		return (ft_hexdump(argc, argv, 0));
	}
	else
		return (error_handler(argc, argv));
}
