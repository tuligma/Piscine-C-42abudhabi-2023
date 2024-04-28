/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:07:31 by npentini          #+#    #+#             */
/*   Updated: 2024/04/29 01:36:37 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*next;
	t_list	*prev;

	if (begin_list == NULL || *begin_list == NULL || data_ref == NULL
		|| cmp == NULL || free_fct == NULL)
		return ;
	current = *begin_list;
	next = NULL;
	prev = *begin_list;
	while (current != NULL)
	{
		next = current->next;
		if (cmp(current->data, data_ref) == 0)
		{
			free_fct(current->data);
			free(current);
			prev->next = next;
		}
		else
			prev = current;
		current = next;
	}
}
