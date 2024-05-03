/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:03:41 by npentini          #+#    #+#             */
/*   Updated: 2024/05/04 01:29:38 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	rush(int x, int y);

int	digit_validator(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
	}
	return (1);
}

int error_handler(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Please provide 2 arguments. <%s> <number> <number>\n", argv[0]);
		return 1;
	}
	if (argc == 3 && (digit_validator(argv[1]) == 0 || digit_validator(argv[2]) == 0))
	{
		printf("Please provide a valid number!!!.\n");
		return 1;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;
	int	error;

	error = error_handler(argc, argv);
	if (error == 1)
		return (error);
	x = (int)atoi(argv[1]);
	y = (int)atoi(argv[2]);
	rush(x, y);
	return (0);
}
