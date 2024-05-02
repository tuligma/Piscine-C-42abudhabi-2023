/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:51:03 by npentini          #+#    #+#             */
/*   Updated: 2024/05/02 15:47:36 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	if (root == NULL || cmpf == NULL || item == NULL)
		return ;
	if (*root == NULL)
		(*root) = btree_create_node(item);
	if (cmpf(item, (*root)->item) < 0)
	{
		if ((*root)->left == NULL)
			(*root)->left = btree_create_node(item);
		else
			btree_insert_data(&(*root)->left, item, cmpf);
	}
	else if (cmpf(item, (*root)->item) > 0)
	{
		if ((*root)->right == NULL)
			(*root)->right = btree_create_node(item);
		else
			btree_insert_data(&(*root)->right, item, cmpf);
	}
}
