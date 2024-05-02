/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:33:17 by npentini          #+#    #+#             */
/*   Updated: 2024/05/02 22:55:51 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	left_count;
	int	right_count;

	if (root == NULL)
		return (0);
	left_count = 0;
	right_count = 0;
	if (root->left != NULL)
		left_count = btree_level_count(root->left);
	if (root->right != NULL)
		right_count = btree_level_count(root->right);
	if (left_count > right_count)
		return (left_count + 1);
	else
		return (right_count + 1);
}
