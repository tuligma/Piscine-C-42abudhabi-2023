/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:25:50 by npentini          #+#    #+#             */
/*   Updated: 2024/05/05 04:54:46 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
int		**arg_to_int(char *str);
int		print_error(int error);
void	print_table(int **table, int rows, int cols);
void	free_array(int	**arr);
int		**free_fail(int **arr, int x);
int		**table_creation(int rows, int cols);


#endif