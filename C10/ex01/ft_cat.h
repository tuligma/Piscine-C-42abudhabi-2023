/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:53:24 by npentini          #+#    #+#             */
/*   Updated: 2024/04/15 04:38:28 by npentini         ###   ########.fr       */
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
void    std_in(char *buff);
char    **ft_basename(int argc, char *argv[]);
int	print_error(char *arg, int error_code);
void    create_write(char *buff, char *arg);
void    append_write(char *buff, char *arg);
int print_out(int argc, char *argv[], char *buff, int buff_size);

#endif