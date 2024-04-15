/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:52:37 by npentini          #+#    #+#             */
/*   Updated: 2024/04/15 11:39:27 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_putstr_err(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(STDERR_FILENO, &str[i], 1);
}

void	ft_putstr_out(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(STDOUT_FILENO, &str[i], 1);
}

void    std_in(char *buff, int buff_size)
{
    int buffer_size;
    
    while (1)
    {
        buffer_size = read(STDIN_FILENO, buff, buff_size);
        buff[buffer_size] = '\0';
        ft_putstr_out(buff);
    }
}

int	print_error(char *arg, int error_code)
{
	ft_putstr_err("cat: ");
	ft_putstr_err(basename(arg));
	ft_putstr_err(": ");
	ft_putstr_err(strerror(error_code));
	ft_putstr_err("\n");
	return (1);
}

int print_out(int argc, char *argv[], char *buff, int buff_size)
{
    int		fd;
	int		buffer_read;
	int		i;

    i = 0;
    while (++i < argc)
	{
		if (argv[i][0] == '-')
			std_in(buff, buff_size);
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			return (print_error(argv[i], errno));
		buffer_read = read(fd, buff, buff_size);
		buff[buffer_read] = '\0';
		if (buffer_read == -1)
			return (print_error(argv[i], errno));
		ft_putstr_out(buff);
        close(fd);
	}
    return (0);
}