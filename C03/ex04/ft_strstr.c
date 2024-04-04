/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:41:53 by npentini          #+#    #+#             */
/*   Updated: 2024/04/05 00:22:38 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	x;
	int	j;

	x = 0;
	if (!(*to_find))
		return (str + x);
	while (*(str + x))
	{
		j = 0;
		if (*(str + x) == *(to_find + j))
		{
			while (*(str + (x + j)) && *(to_find + j)
				&& *(str + (x + j)) == *(to_find + j))
			{
				j++;
				if (!*(to_find + j))
					return (str + x);
			}
		}
		x++;
	}
	return (0);
}
