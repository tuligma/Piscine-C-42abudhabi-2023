/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:35:32 by npentini          #+#    #+#             */
/*   Updated: 2024/05/16 23:35:29 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	x;

	x = -1;
	while (str[++x] != '\0')
		ft_putchar_fd(str[x], fd);
}

int	print_error_free(int error, t_table **table)
{
	if (table != NULL)
		free_table(table, NULL);
	if (error == 1)
		return (0);
	else if (error == 2)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else if (error == -1)
		ft_putstr_fd("Dict Error\n", STDERR_FILENO);
	return (1);
}

int	error_handler(int argc, char *argv[])
{
	if (argc < 2 || argc > 3)
		return (2);
	if (argc == 2 && ft_isdigit(argv[1]) != 0)
		return (2);
	if (argc == 3 && ft_isdigit(argv[2]) != 0)
		return (2);
	return (0);
}

void	print_table(t_table **table, int size)
{
	t_list	*current;
	int		x;

	x = -1;
	while (++x <= size)
	{
		printf("Bucket %d : len %d-> (Key->Value) :", x, table[x]->len);
		current = table[x]->list;
		while (current != NULL)
		{
			printf("(%s->%s) ", current->key, current->value);
			current = current->next;
		}
		printf("\n");
	}
}
