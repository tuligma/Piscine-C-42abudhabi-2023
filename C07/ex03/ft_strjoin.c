/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:28:28 by npentini          #+#    #+#             */
/*   Updated: 2024/04/09 01:35:15 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_strlcat(char *dest, char *src)
{
	int	dest_len;
	int	x;

	dest_len = ft_strlen(dest);
	x = -1;
	while (src[++x] != '\0')
		dest[dest_len + x] = src[x];
}

void 	ft_memset(char *dest, int c, int size)
{
	int i;
	
	i = -1;
	while(++i < size)
		dest[i] = c;
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	char	*dest;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (++i < size)
		len += ft_strlen(str[i]);
	len += (ft_strlen(sep) * (size - 1));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	ft_memset(dest, 0, len);
	i = -1;
	while (++i < size)
	{
		ft_strlcat(dest, str[i]);
		if (i < size - 1)
			ft_strlcat(dest, sep);
	}
	dest[len] = '\0';
	return (dest);
}
