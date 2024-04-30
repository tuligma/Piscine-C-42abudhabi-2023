/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:45:52 by npentini          #+#    #+#             */
/*   Updated: 2024/05/01 00:40:50 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	if (begin_list == NULL)
		return (NULL);
	while (begin_list->next != NULL)
		begin_list = begin_list->next;
	return (begin_list);
}

int	error_handler(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*last;

	if (begin_list1 == NULL || begin_list2 == NULL || cmp == NULL)
		return (1);
	if (*begin_list1 == NULL)
	{
		last = ft_list_last(begin_list2);
		last->next = *begin_list1;
		*begin_list1 = begin_list2;
		return (1);
	}
	return (0);
}

void	sorted_list_insert(t_list **begin_list1, t_list *current1, int (*cmp)())
{
	t_list	*current;
	t_list	*prev;

	current = *begin_list1;
	prev = NULL;
	while (current != NULL && cmp(current1->data, current->data) > 0)
	{
		prev = current;
		current = current->next;
	}
	if (prev == NULL)
	{
		current1->next = *begin_list1;
		*begin_list1 = current1;
	}
	else
	{
		current1->next = prev->next;
		prev->next = current1;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1,
	t_list *begin_list2, int (*cmp)())
{
	t_list	*current1;
	t_list	*next;
	int		error;

	error = error_handler(begin_list1, begin_list2, cmp);
	if (error == 1)
		return ;
	current1 = begin_list2;
	next = NULL;
	while (current1 != NULL)
	{
		next = current1->next;
		sorted_list_insert(begin_list1, current1, cmp);
		current1 = next;
	}
}
