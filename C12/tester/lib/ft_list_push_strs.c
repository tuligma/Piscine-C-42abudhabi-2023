/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:21:57 by npentini          #+#    #+#             */
/*   Updated: 2024/04/28 00:44:23 by npentini         ###   ########.fr       */
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*node;
	t_list	*current;
	int		x;

	current = NULL;
	x = -1;
	while (++x < size)
	{
		node = ft_create_elem(strs[x]);
		if (node == NULL)
			return (NULL);
		if (current == NULL)
			current = node;
		else
		{
			node->next = current;
			current = node;
		}
	}
	return (current);
}
