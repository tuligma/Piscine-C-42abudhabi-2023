/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 01:20:18 by npentini          #+#    #+#             */
/*   Updated: 2024/04/07 01:58:15 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	sqrt = 2;
	while (sqrt <= nb / sqrt && sqrt <= 46340)
	{
		if ((sqrt * sqrt == nb))
			return (sqrt);
		++sqrt;
	}
	return (0);
}
