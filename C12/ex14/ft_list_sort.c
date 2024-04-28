/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 02:43:50 by npentini          #+#    #+#             */
/*   Updated: 2024/04/29 02:57:16 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*next;
	t_list	*prev;
	t_list	*temp;

	if (begin_list == NULL || *begin_list == NULL || cmp == NULL)
		return ;
	current = *begin_list;
	next = NULL;
	prev = *begin_list;
	while (current != NULL)
	{
		temp = current;
		while (temp != NULL)
		{
			next = temp->next
			if (cmp(temp, next) < 0)
			{
				
			}
		}
	}
}
