/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_tester.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:24:43 by npentini          #+#    #+#             */
/*   Updated: 2024/04/12 13:29:09 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex03/ft_point.h"
#include <stdio.h>

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int	main(void)
{
	t_point	point;
	
	set_point(&point);
	printf("\n\n x: %d | y: %d\n\n", point.x, point.y);
	return (0);
}