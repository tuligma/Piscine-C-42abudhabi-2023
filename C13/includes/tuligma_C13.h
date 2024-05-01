/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuligma_C13.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:05:42 by npentini          #+#    #+#             */
/*   Updated: 2024/05/02 02:25:37 by npentini         ###   ########.fr       */
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

#endif