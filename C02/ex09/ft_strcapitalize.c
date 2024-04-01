/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 02:08:40 by npentini          #+#    #+#             */
/*   Updated: 2024/04/01 04:42:02 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	delimiter(char c)
{
	if (c == ' ' || c == '-' || c == '+' || c == '.' || c == '\0')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i;
		while (delimiter(str[j]) && str[j] != '\0')
		{
			j++;
			if (!delimiter(str[j]) && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
		}
		i = j + 1;
	}
	return (str);
}
