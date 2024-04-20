/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:25:22 by npentini          #+#    #+#             */
/*   Updated: 2024/04/21 02:01:25 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

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
		ft_putchar(str[i]);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr_out("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	total_buffer_size(char *argv, int buffer_size)
{
	char	*buff;
	int		fd;
	int		count;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	while (buffer_size > 0)
	{
		count += buffer_size;
		buff = (char *)malloc(sizeof(char) * 16);
		if (buff == NULL)
			return (-1);
		buffer_size = read(fd, buff, 16);
		if (buffer_size == -1)
			return (-1);
		free(buff);
	}
	return (count - 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

void	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	copy_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	copy_len = size - dest_len - 1;
	i = -1;
	while (src[++i] != '\0' && copy_len-- > 0)
		dest[dest_len++] = src[i];
	dest[dest_len] = '\0';
}