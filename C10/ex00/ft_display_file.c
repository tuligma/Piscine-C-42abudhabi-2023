/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:35:12 by npentini          #+#    #+#             */
/*   Updated: 2024/04/14 15:14:29 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_display_file.h"

int	main(int argc, char *argv[])
{
	char	buffer[1024];
	int		fd;
	int		buffer_read;

	if (argc == 1)
	{
		ft_putstr_err("File name missing.\n");
		return (1);
	}
	else if (argc > 2)
	{
		ft_putstr_err("Too many Arguments.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	buffer_read = read(fd, buffer, sizeof(buffer));
	if (buffer_read == -1 || fd == -1)
	{
		ft_putstr_err("Cannot read file.\n");
		return (1);
	}
	buffer[buffer_read] = '\0';
	ft_putstr_out(buffer);
	close(fd);
	return (0);
}
