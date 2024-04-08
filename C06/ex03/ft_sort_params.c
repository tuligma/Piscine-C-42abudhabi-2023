/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:28:45 by npentini          #+#    #+#             */
/*   Updated: 2024/04/08 18:15:53 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	sort_params(char *argv)
{
	char	temp;
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ft_strlen(argv);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (argv[j] > argv[j + 1])
			{
				temp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	j;
	int	i;

	if (argc <= 1)
		return (1);
	i = 0;
	while (++i < argc)
	{
		sort_params(argv[i]);
		j = -1;
		while (argv[i][++j] != '\0')
			write(1, &argv[i][j], 1);
		write(1, "\n", 1);
	}
	return (0);
}
