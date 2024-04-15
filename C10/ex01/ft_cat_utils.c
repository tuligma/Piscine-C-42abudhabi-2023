/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 03:04:18 by npentini          #+#    #+#             */
/*   Updated: 2024/04/15 11:52:20 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void    create_write(char *buff, char *arg, int buff_size)
{
    int fd;
    int buffer_size;
    int write_size;

    fd = open(arg, O_CREAT | O_WRONLY);
    if (fd == -1)
        print_error(arg, errno);
    while (1)
    {
        buffer_size = read(STDIN_FILENO, buff, buff_size);
         if (buffer_size == -1)
         {
            print_error(buff, errno);
            return ;
         }
        buff[buffer_size] = '\0';
        write_size = write(fd, buff, buffer_size);
        if (write_size == -1)
        {
            print_error(buff, errno);
            return ;
        }
    }
}

void    append_write(char *buff, char *arg, int buff_size)
{
    int fd;
    int buffer_size;
    int write_size;

   
    fd = open(arg, O_CREAT | O_APPEND | O_WRONLY);
    if (fd == -1)
        print_error(arg, errno);
    while (1)
    {
        buffer_size = read(STDIN_FILENO, buff, buff_size);
        if (buffer_size == -1)
         {
            print_error(buff, errno);
            return ;
         }
        buff[buffer_size] = '\0';
        write_size = write(fd, buff, buffer_size);
        if (write_size == -1)
        {
            print_error(buff, errno);
            return ;
        }
    }
}

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}
