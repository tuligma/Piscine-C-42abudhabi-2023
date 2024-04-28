/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:54:00 by npentini          #+#    #+#             */
/*   Updated: 2024/04/29 01:24:12 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next;
	t_list	*current;

	if (begin_list == NULL || free_fct == NULL)
		return ;
	current = begin_list;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free_fct(current->data);
		free(current);
		current = next;
	}
}
