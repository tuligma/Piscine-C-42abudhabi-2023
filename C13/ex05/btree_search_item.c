/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:32:55 by npentini          #+#    #+#             */
/*   Updated: 2024/05/02 21:31:32 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *))
{
	void	*found;

	if (root == NULL || data_ref == NULL || cmpf == NULL)
		return (NULL);
	if (cmpf(data_ref, root->item) < 0)
	{
		found = btree_search_item(root->left, data_ref, cmpf);
		if (found != NULL)
			return (found);
	}
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	if (cmpf(data_ref, root->item) > 0)
	{
		found = btree_search_item(root->right, data_ref, cmpf);
		if (found != NULL)
			return (found);
	}
	return (NULL);
}
