/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:03:45 by npentini          #+#    #+#             */
/*   Updated: 2024/04/27 03:35:37 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

int		addition(int a, int b);
int		subtraction(int a, int b);
int		division(int a, int b);
int		multiplication(int a, int b);
int		modulo(int a, int b);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		operator_validator(char c);
int		error_handler(int argc, char *argv[]);
int		error_print(char *argv[]);
int		do_op(char op, int value1, int value2);

#endif