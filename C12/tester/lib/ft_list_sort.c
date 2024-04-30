/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 02:43:50 by npentini          #+#    #+#             */
/*   Updated: 2024/05/01 00:41:01 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*out_current;
	t_list	*in_current;
	t_list	*in_next;
	t_list	*temp;

	if (begin_list == NULL || *begin_list == NULL || cmp == NULL)
		return ;
	out_current = *begin_list;
	in_next = NULL;
	while (out_current != NULL)
	{
		in_current = *begin_list;
		while (in_current->next != NULL)
		{
			in_next = in_current->next;
			if (cmp(in_current->data, in_next->data) > 0)
			{
				temp = in_current->data;
				in_current->data = in_next->data;
				in_next->data = temp;
			}
			in_current = in_current->next;
		}
		out_current = out_current->next;
	}
}
