/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:15:27 by npentini          #+#    #+#             */
/*   Updated: 2024/05/11 05:30:44 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

void	hundreds_up(char *str, h_list **table, int x, int len)
{
	t_list *current;
	int j;

	j = 0;
	current = table[j]->list;
	while (current != NULL && (str[x] - '0') != ft_atoi(current->key))
		current = current->next;
	ft_putstr_fd(current->value, STDOUT_FILENO);
	ft_putchar_fd(' ', STDOUT_FILENO);
	j = 0;
	while (table[j] != NULL && table[j]->len != len)
		j++;
	current = table[j]->list;
	while (current->next != NULL && ft_strcmp(str, current->key) != 0)
		current = current->next;
	ft_putstr_fd(current->value, STDOUT_FILENO);
}

int	search_arg1(char *str, h_list **table)
{
	int	len;
	int	x;

	len = ft_strlen(str);
	x = -1;
	if (len == 2 && ft_atoi(str) >= 11 && ft_atoi(str) <= 19)
		len =-1;
	while (str[++x] != '\0' && len > 0)
	{
		if (len > 2)
		{
			if ((str[x] - '0') != 0)
			{
				hundreds_up(str, table, x, len);
				len--;
				if (len > 2)
					ft_putchar_fd(' ', STDOUT_FILENO);
			}
			else
				len--;
		}
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		status;
	h_list **table;

	status = error_handler(argc, argv);
	if (status != 0)
		return (print_error(status));
	table = extract_create(argc, argv);
	if (table == NULL)
		return (print_error(status));
	status = search_arg1(argv[1], table);
	if (status != 0)
	{
		free_table(table, NULL);
		return (print_error(status));
	}
	free_table(table, NULL);
	return (0);
}