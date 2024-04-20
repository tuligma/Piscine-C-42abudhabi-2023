/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:43:24 by npentini          #+#    #+#             */
/*   Updated: 2024/04/20 04:13:24 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <libgen.h>
# include <errno.h>
# include <stdio.h>

void	ft_putstr_err(char *str);
void	ft_putstr_out(char *str);
int		ft_isdigit(char *str);
int		ft_atoi(char *str);
int		total_buff_size(char *arg, int byte_size, int buff_size);
int		read_print(char *buff, char *arg, int buff_size);
int		execute_read(char *arg, int byte_size, char **buff);
int		ft_tail(int argc, char *argv[], int byte_size, int fail);
void	print_head(char *arg);
int		print_error(char *arg, int error_code);
int		print_error_byte(char *arg);
int		print_single_out(char *arg, int byte_size, int *prev_result, int argc);
int		print_multi_out(char *arg, int byte_size, int *prev_result, int argc);
int		error_handler(int argc, char *argv[]);

#endif