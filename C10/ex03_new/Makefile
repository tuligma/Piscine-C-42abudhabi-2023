# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 19:44:18 by npentini          #+#    #+#              #
#    Updated: 2024/04/22 00:26:08 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump
SRCS = ft_hexdump.c ft_hexdump_print.c ft_hexdump_utils.c ft_hexdump_utils2.c
INCS = .
COMP = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = ft_hexdump.o ft_hexdump_print.o ft_hexdump_utils.o ft_hexdump_utils2.o
DELETE = rm -f

all: $(NAME)

%.o : %.c
	$(COMP) $(CFLAGS) -I $(INCS) -c $< -o $@ -g

$(NAME) : $(OBJS)
	$(COMP) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(DELETE) $(OBJS)

fclean: clean
	$(DELETE) $(NAME)

re: clean fclean

.PHONY: all clean fclean re