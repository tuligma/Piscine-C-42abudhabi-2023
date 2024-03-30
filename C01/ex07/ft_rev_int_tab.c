/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 02:11:26 by npentini          #+#    #+#             */
/*   Updated: 2024/03/31 02:33:24 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		temp;

	i = -1;
	while (++i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i -1];
		tab[size - i - 1] = temp;
	}
}
