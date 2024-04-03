/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:35:22 by npentini          #+#    #+#             */
/*   Updated: 2024/04/03 12:23:13 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hex_memory(unsigned long int x)
{
	char	hex[16];
	int		i;
	int		y;

	i = -1;
	while (++i < 16)
		hex[i] = '\0';
	i = 16;
	while (--i)
	{
		y = x % 16;
		if (y < 10)
			hex[i - 1] = '0' + y;
		else
			hex[i - 1] = 'a' + (y - 10);
		x /= 16;
	}
	write(1, hex, 16);
	write(1, ":", 1);
}

void	string_hex(char *str, unsigned int size)
{
	unsigned int	i;
	unsigned int	limit;

	i = 0;
	limit = 16;
	while (i < size - 1 && i < limit)
	{
		if (!(i % 2))
			write(1, " ", 1);
		write(1, &"0123456789abcdef"[((unsigned char)str[i]) / 16], 1);
		write(1, &"0123456789abcdef"[((unsigned char)str[i]) % 16], 1);
		i++;
	}
	--i;
	while (++i <= limit)
		write(1, " ", 1);
}

void	string_print(char *str, unsigned int size)
{
	unsigned int	i;
	unsigned int	limit;

	i = 0;
	limit = 16;
	while (--size && limit--)
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	if (size == 1)
		return (addr);
	hex_memory((unsigned long int)addr);
	string_hex((char *)addr, size);
	string_print((char *)addr, size);
	return (addr);
}
