/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:40:06 by npentini          #+#    #+#             */
/*   Updated: 2024/04/14 15:18:06 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_display_file.h"

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
	write(STDOUT_FILENO, "\n", 1);
}
