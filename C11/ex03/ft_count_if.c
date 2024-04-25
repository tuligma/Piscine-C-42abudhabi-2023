/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 01:47:33 by npentini          #+#    #+#             */
/*   Updated: 2024/04/26 02:13:50 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	x;

	if (tab == NULL || length == 0 || f == NULL)
		return (0); 
	count = 0;
	x = -1;
	while (++x < length)
	{
		if (tab[x] != NULL && f(tab[x]) !=0)
			count++;
	}
	return (count);
}
