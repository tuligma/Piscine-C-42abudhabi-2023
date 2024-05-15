/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:13:27 by npentini          #+#    #+#             */
/*   Updated: 2024/05/16 01:56:25 by npentini         ###   ########.fr       */
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
	t_list	*list;
}			t_table;

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_isdigit(char *str);
int		ft_atoi(char *str);
char	*ft_strdup(char *src, int size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
int		print_error_free(int error, t_table **table);
int		error_handler(int argc, char *argv[]);
int		dict_parse(char **buff, char *file);
int		filesize(char *file);
int		table_size(char *str);
int		key_size(char *str, int size);
t_table	**table_creation(int size);
void	*free_table(t_table **table, char *str);
int		data_processing(t_table **table, char *str);
char	*key_extraction(char *str, int size);
char	*value_extraction(char *str, int size);
int		value_size(char *str, int size);
int		word_counter(char *str, int size);
int		insert_htable(t_table **table, char *key, char *value, int key_len);
t_list	*ft_create_elem(char *key, char *value);
int		search_per_order(char *str, t_table **table, int len, int full_len);
int		order_magnitude(t_table **table, int len);
int		handle_large_number(char *str, t_table **table, int len, int *x);
int		handle_thousands_up(char *str, t_table **table, int len, int *x);
int		ones(char *str, t_table **table);
int		hundreds_up(char *str, t_table **table, int len);
int		tens(char *str, t_table **table);
int		handle_ones(char *str, t_table **table, int *len, int full_len);
int		handle_tens(char *str, t_table **table, int *len, int full_len);
int		handle_hundreds(char *str, t_table **table, int *len, int full_len);
t_table	**extract_create(int argc, char *argv[]);
int		search_arg1(char *str, t_table **table);
int		zero_arg(char *str, t_table **table);
int		zeros(char *str);

void	print_table(t_table **table, int size);

#endif