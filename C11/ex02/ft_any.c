/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 01:12:04 by npentini          #+#    #+#             */
/*   Updated: 2024/04/26 02:14:43 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int	x;
	int	result;

	if (tab == NULL || f == NULL)
		return (0);
	x = -1;
	while (tab[++x] != NULL)
	{
		if (f(tab[x]) != 0)
			return (1);
	}
	return (0);
}
