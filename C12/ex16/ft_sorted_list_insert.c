/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 02:41:48 by npentini          #+#    #+#             */
/*   Updated: 2024/04/30 03:43:54 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current;
	t_list	*node;
	t_list	*position;

	if (begin_list == NULL || *begin_list == NULL || cmp == NULL )
		return ;
	current = *begin_list;
	node = ft_create_elem(data);
	if (node == NULL)
		return ;
	position = NULL;
	while (current != NULL && cmp(node->data, current->data) > 0)
	{
		position = current;
		current = current->next;
	}
	if (position == NULL)
		*begin_list = node;
	else
		position->next = node;
	node->next = current;
}
