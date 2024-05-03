/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:03:33 by npentini          #+#    #+#             */
/*   Updated: 2024/05/03 19:37:17 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_node_count(t_btree *root)
{
	int	count;

	if (root == NULL)
		return (0);
	count = btree_node_count(root->left);
	count += btree_node_count(root->right);
	return (count + 1);
}

void	process_level(t_btree **queue, int	*head, int *tail,
		void (*applyf)(void *item,
			int current_level, int is_first))
{
	t_btree	*current;
	int		level;
	int		is_first;
	int		i;

	level = *tail - *head;
	is_first = 1;
	i = -1;
	while (++i < level)
	{
		current = queue[++(*head)];
		applyf(current->item, level, is_first);
		is_first = 0;
		if (current->left != NULL)
			queue[++(*tail)] = current->left;
		if (current->right != NULL)
			queue[++(*tail)] = current->right;
	}
}

void	btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item,
			int current_level, int is_first))
{
	t_btree	**queue;
	int		head;
	int		tail;

	if (root == NULL || applyf == NULL)
		return ;
	queue = (t_btree **)malloc(sizeof(t_btree *) * btree_node_count(root));
	if (queue == NULL)
		return ;
	head = -1;
	tail = -1;
	queue[++tail] = root;
	while (head < tail)
		process_level(queue, &head, &tail, applyf);
	free(queue);
}
