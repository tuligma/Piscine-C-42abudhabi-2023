/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:13:27 by npentini          #+#    #+#             */
/*   Updated: 2024/05/08 04:23:17 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	char			*key;
	char			*value;
}					t_list;

typedef struct s_arr
{
	int		len;
	t_list	**list;
}			h_list;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_isdigit(char *str);
int		ft_atoi(char *str);
int		print_error(int error);
int		error_handler(int argc, char *argv[]);
int		filesize(void);
int		dict_parse(char **buff);
int		table_size(char *str);
int		key_size(char *str, int size);
h_list	**table_creation(int size);
void	free_table(h_list **table);

#endif