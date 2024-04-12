# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/13 01:15:38 by npentini          #+#    #+#              #
#    Updated: 2024/04/13 01:53:52 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
INCS = includes
COMP = cc -c
CFLAGS = -Wall -Wextra -Werror
OBJS = srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o
DELETE = rm -f
LIB_CREATE = ar rcs
RANLIB = ranlib

all: $(NAME)

srcs/%.o: srcs/%.c
	$(COMP) $(CFLAGS) -I $(INCS) -o $@ $<

$(NAME): $(OBJS)
	$(LIB_CREATE) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	$(DELETE) $(OBJS)

fclean: clean
	$(DELETE) $(NAME)

re: fclean all

.PHONY: all clean fclean re