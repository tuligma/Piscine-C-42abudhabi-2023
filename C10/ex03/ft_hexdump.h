/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:45:46 by npentini          #+#    #+#             */
/*   Updated: 2024/04/21 01:48:34 by npentini         ###   ########.fr       */
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

void	ft_putchar(char c);
void	ft_putstr_err(char *str);
void	ft_putstr_out(char *str);
void	ft_putnbr(int nb);
int		print_error(char *arg, int error_code);
int		print_error_arg(char *arg);
int		error_handler(int argc, char *argv[]);
int		total_buffer_size(char *argv, int buffer_size);
int		off_set_byte(int j);
int		string_process(char *argv[], char **buffer, int total_size);
void	string_hex_print(char *str, unsigned int size);
void	string_print(char *str, unsigned int size);
void	ft_strlcat(char *dest, const char *src, size_t size);
int		buffer_extraction(int argc, char *argv[], char **buffer, int total_size);
int		open_read(char *arg, char **buffer, int arg_size, int total_size);
#endif