/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:06:18 by npentini          #+#    #+#             */
/*   Updated: 2024/04/24 23:55:23 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <libgen.h>
# include <errno.h>
# include <stdio.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
int		buff_offset(char *arg, char **buff, int buff_size);
int		offset_pointer(int fd, int *offset_ptr);
int		open_arg(char *arg, int *offset_ptr);
int		print_error_flag(char *arg);
int		print_error(char *arg, int error_code);
int		error_handler(int argc, char *argv[]);
int		off_set_byte(int j);
int		total_size(int argc, char *argv[]);
int		arg_size(char *arg, int buff_size);
void	string_hex_print(char *str, int size);
void	string_print(char *str, int size);
int		print_all(char *buff, int buff_size, int offset_ptr, int i);

#endif