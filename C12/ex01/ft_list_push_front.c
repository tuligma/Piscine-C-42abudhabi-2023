/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:21:07 by npentini          #+#    #+#             */
/*   Updated: 2024/04/30 03:41:44 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_node;

	if (begin_list == NULL || data == NULL)
		return ;
	new_node = ft_create_elem(data);
	if (new_node == NULL)
		return ;
	new_node->next = *begin_list;
	*begin_list = new_node;
}
