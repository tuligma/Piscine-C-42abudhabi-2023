/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:43:24 by npentini          #+#    #+#             */
/*   Updated: 2024/04/17 04:52:17 by npentini         ###   ########.fr       */
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

int		ft_isdigit(char *str);
int		ft_atoi(char *str);
int		total_buff_size(char *arg, int byte_size, int buff_size);
int		read_print(int argc, char *arg, int buff_size, int byte_size);
int		execute_read(int argc, char *arg, int byte_size);
int		print_error(char *arg, int error_code);
int		print_error_byte(char *arg);
void	ft_putstr_err(char *str);
void	ft_putstr_out(char *str);
void	print_head(char *arg);

#endif