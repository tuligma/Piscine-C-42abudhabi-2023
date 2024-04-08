/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:11:52 by npentini          #+#    #+#             */
/*   Updated: 2024/04/08 22:27:24 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*dest;

	if (min >= max)
	{	
		*range = NULL;
		return (0);
	}
	size = max - min;
	dest = (int *)malloc(sizeof(int) * size);
	if (!dest)
		return (-1);
	i = -1;
	while (++i < size)
		dest[i] = min++;
	*range = dest;
	return (size);
}
