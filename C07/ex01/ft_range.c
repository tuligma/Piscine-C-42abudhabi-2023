/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:37:57 by npentini          #+#    #+#             */
/*   Updated: 2024/04/08 21:36:13 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	dest = (int *)malloc(sizeof(int) * size);
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < size)
		dest[i] = min++;
	return (dest);
}
