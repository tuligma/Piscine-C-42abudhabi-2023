/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:31:51 by npentini          #+#    #+#             */
/*   Updated: 2024/04/15 12:12:36 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"


int main(int argc, char *argv[])
{
	char	buff[2999];
	int		buff_size;
	int		single_operator;
	int		double_operator;

	single_operator = ft_strlen(">");
	double_operator = ft_strlen(">>");
	buff_size = sizeof(buff);
	if (argc == 1)
		std_in(buff, buff_size);
	else if (argc == 3 && argv[1][0] == '>' && single_operator == 1)
		create_write(buff, argv[2], buff_size);
	else if (argc == 3 && argv[1][0] == '>' && argv[1][1] == '>' && double_operator == 2)
		append_write(buff, argv[2], buff_size);
	return (print_out(argc, argv, buff, buff_size));
}
