/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:53:24 by npentini          #+#    #+#             */
/*   Updated: 2024/04/15 12:05:39 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>
#include <stdio.h>

void	ft_putstr_err(char *str);
void	ft_putstr_out(char *str);
void    std_in(char *buff, int buff_size);
char    **ft_basename(int argc, char *argv[]);
int	print_error(char *arg, int error_code);
void    create_write(char *buff, char *arg, int buff_size);
void    append_write(char *buff, char *arg, int buff_size);
int print_out(int argc, char *argv[], char *buff, int buff_size);
int ft_strlen(char *str);

#endif