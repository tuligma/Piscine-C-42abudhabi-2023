/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 03:04:18 by npentini          #+#    #+#             */
/*   Updated: 2024/04/15 04:55:18 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void    create_write(char *buff, char *arg)
{
    int fd;
    int buffer_size;
    int write_size;

    fd = open(arg, O_CREAT | O_WRONLY);
    if (fd == -1)
        print_error(arg, errno);
    while (1)
    {
        buffer_size = read(STDIN_FILENO, buff, sizeof(buff));
         if (buffer_size == -1)
            print_error(buff, errno);
        buff[buffer_size] = '\0';
        write_size = write(fd, buff, buffer_size);
        if (write_size == -1)
            print_error(buff, errno);
    }
}

void    append_write(char *buff, char *arg)
{
    int fd;
    int buffer_size;
    int write_size;

    fd = open(arg, O_RDONLY);
    if (errno == 2)
    {
        close(fd);
        create_write(buff, arg);
        return ;
    }
    else
    {
        close(fd);
        fd = open(arg, O_APPEND | O_WRONLY);
        if (fd == -1)
            print_error(arg, errno);
        while (1)
        {
            buffer_size = read(STDIN_FILENO, buff, sizeof(buff));
            if (buffer_size == -1)
                print_error(buff, errno);
            buff[buffer_size] = '\0';
            write_size = write(fd, buff, buffer_size);
            if (write_size == -1)
                print_error(buff, errno);
        }
    }
}
