/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:31:51 by npentini          #+#    #+#             */
/*   Updated: 2024/04/15 04:38:11 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"


int main(int argc, char *argv[])
{
	char	buff[2999];
	int		buff_size;

	if (argc == 1 || (argc == 2 && argv[1][0] == '-'))
		std_in(buff);
	else if (argc == 3 && argv[1][0] == '>')
		create_write(buff, argv[2]);
	else if (argc == 3 && argv[1][0] == '>' && argv[1][1] == '>')
		append_write(buff, argv[2]);
	buff_size = sizeof(buff);
	return (print_out(argc, argv, buff, buff_size));
}
