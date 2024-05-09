/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:35:32 by npentini          #+#    #+#             */
/*   Updated: 2024/05/08 04:15:40 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	x;

	x = -1;
	while (str[++x] != '\0')
		ft_putchar_fd(str[x], fd);
}

int	print_error(int error)
{
	if (error == 2)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	if (error == -1)
		ft_putstr_fd("Dict Error\n", STDERR_FILENO);
	return (1);
}
