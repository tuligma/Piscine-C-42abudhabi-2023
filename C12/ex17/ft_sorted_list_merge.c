/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:45:52 by npentini          #+#    #+#             */
/*   Updated: 2024/04/30 04:40:31 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*current;
	t_list	*position;

	if (begin_list1 == NULL || begin_list2 == NULL || cmp == NULL)
		return ;
	position = NULL;
	while (begin_list2 != NULL)
	{
		current = *begin_list1;
		while (current->next != NULL && cmp(begin_list2->data, current->data) > 0)
		{
			position = current;
			current = current->next;
		}
		if (position == NULL)
			*begin_list1 = begin_list2;
		else
			position->next = begin_list2;
		begin_list2 = begin_list2->next;
	}
}
