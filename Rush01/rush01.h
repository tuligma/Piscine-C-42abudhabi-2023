/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:25:50 by npentini          #+#    #+#             */
/*   Updated: 2024/05/06 05:30:19 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_strcmp(char *s1, char *s2);
int		**arg_to_int(char *str);
int		print_error(void);
void	print_table(int **table, int rows, int cols);
void	free_array(int	**arr);
int		**free_fail(int **arr, int x);
int		**table_creation(int rows, int cols);
void	rowlf_map(int **arg, int **table, int rows);
void	colup_map(int **arg, int **table, int cols);
void	verifier_rows(int **table, int rows, int cols);
void	verifier_cols(int **table, int rows, int cols);
void	verifier_remaining(int **arg, int **table, int rows, int cols);
int		**rush01(int **arg);
int		mapping(int **arg, int **table, int rows, int cols);
int		checker(int **table);

#endif