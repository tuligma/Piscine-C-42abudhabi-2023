/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:51:03 by npentini          #+#    #+#             */
/*   Updated: 2024/05/02 03:09:03 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	t_btree	*node;

	if (root == NULL || cmpf == NULL || item == NULL)
		return ;
	node = btree_create_node(item);
	if (node == NULL)
		return ;
	if (*root == NULL)
		(*root) = node;
	else if (cmpf(item, (*root)->item) < 0)
	{
		if ((*root)->left != NULL)
			btree_insert_data(&(*root)->left, item, cmpf);
		(*root)->left = node;
	}
	else if (cmpf(item, (*root)->item) > 0)
	{
		if ((*root)->right != NULL)
			btree_insert_data(&(*root)->right, item, cmpf);
		(*root)->right = node;
	}
}
