/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:22:34 by npentini          #+#    #+#             */
/*   Updated: 2024/04/30 02:38:10 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	x;

	x = 0;
	while (begin_list != NULL)
	{
		x++;
		begin_list = begin_list->next;
	}
	return (x);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*current;
	t_list	*temp;
	int		size;
	int		x;
	int		i;

	if (begin_list == NULL)
		return ;
	size = ft_list_size(begin_list);
	x = -1;
	while (++x < size / 2)
	{
		current = begin_list;
		i = -1;
		while (++i + x < size - 1 - x)
			current = current->next;
		temp = begin_list->data;
		begin_list->data = current->data;
		current->data = temp;
		begin_list = begin_list->next;
	}
}
