/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:18:25 by npentini          #+#    #+#             */
/*   Updated: 2024/04/08 14:24:23 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	j;

	if (argc <= 1)
		return (1);
	while (--argc >= 1)
	{
		j = -1;
		while (argv[argc][++j] != '\0')
			write(1, &argv[argc][j], 1);
		write(1, "\n", 1);
	}
	return (0);
}