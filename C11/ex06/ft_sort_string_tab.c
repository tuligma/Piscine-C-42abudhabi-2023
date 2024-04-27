/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 03:47:48 by npentini          #+#    #+#             */
/*   Updated: 2024/04/27 04:31:21 by npentini         ###   ########.fr       */
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

void	ft_sort_string_tab(char **tab)
{
	char	*temp;
	int		len;
	int		x;
	int		j;

	if (tab == NULL)
		return ;
	len = ft_arrlen(tab);
	x = -1;
	while (++x < len)
	{
		j = -1;
		while (++j < len - 1)
		{
			if (tab[j][0] > tab[j + 1][0])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
		}
	}
}
