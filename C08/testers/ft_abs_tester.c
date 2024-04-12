/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:14:45 by npentini          #+#    #+#             */
/*   Updated: 2024/04/12 13:19:55 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex02/ft_abs.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	n;
	if (argc != 2)
	{
		printf("\n\nPlease provide the number to check for the absolute value!\n\n");
		return (1);
	}

	n = atoi(argv[1]);
	printf("\n\n the absolute value of %d is (%d)\n\n", n, ABS(n));
	return (0); 


}