/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:41:29 by npentini          #+#    #+#             */
/*   Updated: 2024/04/28 23:57:08 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	x;

	if (begin_list == NULL)
		return (NULL);
	else if (nbr == 0)
		return (begin_list);
	x = 0;
	while (begin_list != NULL && x++ < nbr)
		begin_list = begin_list->next;
	if (x < nbr)
		return (NULL);
	return (begin_list);
}
