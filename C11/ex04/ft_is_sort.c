/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 02:15:59 by npentini          #+#    #+#             */
/*   Updated: 2024/04/26 02:37:36 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	x;

	if (tab == NULL || length == 0 || f == NULL)
		return (0);
	x = -1;
	while (++x < length && x + 1 < length)
	{
		if (f(tab[x], tab[x + 1]) > 0)
			return (0);
	}
	return (1);
}
