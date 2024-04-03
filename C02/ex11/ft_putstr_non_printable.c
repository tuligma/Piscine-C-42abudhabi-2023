/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:39:37 by npentini          #+#    #+#             */
/*   Updated: 2024/04/01 16:00:58 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[((unsigned char)str[i]) / 16], 1);
			write(1, &"0123456789abcdef"[((unsigned char)str[i]) % 16], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
