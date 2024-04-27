/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 04:29:52 by npentini          #+#    #+#             */
/*   Updated: 2024/04/27 04:35:20 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_arrlen(char **tab)
{
	int	x;

	x = 0;
	while (tab[x] != NULL)
		x++;
	return (x);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char*, char*))
{
	char	*temp;
	int		len;
	int		x;
	int		j;

	if (tab == NULL || cmp == NULL)
		return ;
	len = ft_arrlen(tab);
	x = -1;
	while (++x < len)
	{
		j = -1;
		while (++j < len - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
		}
	}
}
