/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 04:53:38 by npentini          #+#    #+#             */
/*   Updated: 2024/04/01 05:36:41 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size > 0)
	{
		i = -1;
		while (++i < size - 1 && src[i] != '\0')
			dest[i] = src[i];
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
