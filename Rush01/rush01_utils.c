/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:28:11 by npentini          #+#    #+#             */
/*   Updated: 2024/05/06 04:40:15 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	free_array(int	**arr)
{
	int	x;

	x = -1;
	while (arr[++x] != NULL)
		free(arr[x]);
	free(arr[x]);
	free(arr);
	arr = NULL;
}

int	**free_fail(int **arr, int x)
{
	while (x > 0)
		free(arr[x--]);
	free(arr);
	return (NULL);
}
