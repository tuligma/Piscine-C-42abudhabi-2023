/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:54:51 by npentini          #+#    #+#             */
/*   Updated: 2024/04/30 03:41:05 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_node;
	t_list	*current;

	if (begin_list == NULL || data == NULL)
		return ;
	new_node = ft_create_elem(data);
	if (new_node == NULL)
		return ;
	if (*begin_list == NULL)
	{
		*begin_list = new_node;
	}
	current = *begin_list;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}
