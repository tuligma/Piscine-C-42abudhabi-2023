/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuligma_C11.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:22:19 by npentini          #+#    #+#             */
/*   Updated: 2024/04/27 04:29:16 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TULIGMA_C11_H
# define TULIGMA_C11_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

void	ft_foreach(int *tab, int length, void (*f)(int));
int		*ft_map(int *tab, int length, int (*f)(int));
int		ft_any(char **tab, int (*f)(char*));
int		ft_count_if(char **tab, int length, int (*f)(char*));
int		ft_is_sort(int *tab, int length, int (*f)(int, int));
int		ft_sort_string_tab(char **tab);
int		ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char*));

#endif