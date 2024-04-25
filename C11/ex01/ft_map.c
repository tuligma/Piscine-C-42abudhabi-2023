/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:43:41 by npentini          #+#    #+#             */
/*   Updated: 2024/04/25 23:51:04 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new_tab;
	int	x;

	if (tab == NULL || f == NULL)
		return (NULL);
	new_tab = (int *)malloc(sizeof(int) * length);
	if (new_tab == NULL)
		return (NULL);
	x = -1;
	while (++x < length)
		new_tab[x] = f(tab[x]);
	return (new_tab);
}
