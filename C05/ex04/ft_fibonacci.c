/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:29:26 by npentini          #+#    #+#             */
/*   Updated: 2024/04/06 22:53:49 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	fib1;
	int	fib2;

	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index);
	fib1 = ft_fibonacci(index - 2);
	fib2 = ft_fibonacci(index - 1);
	return (fib1 + fib2);
}
