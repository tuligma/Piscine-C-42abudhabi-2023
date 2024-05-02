/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuligma_C13.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:05:42 by npentini          #+#    #+#             */
/*   Updated: 2024/05/02 23:26:28 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TULIGMA_C13_H
# define TULIGMA_C13_H

#include <stdio.h>
#include <stdlib.h>
#include "../ex00/ft_btree.h"

t_btree	*btree_create_node(void *item);
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
int		btree_level_count(t_btree *root);
void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first));

#endif