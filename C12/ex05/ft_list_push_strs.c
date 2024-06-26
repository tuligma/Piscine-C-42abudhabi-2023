/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:21:57 by npentini          #+#    #+#             */
/*   Updated: 2024/04/30 03:41:16 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
