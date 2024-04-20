# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 19:44:18 by npentini          #+#    #+#              #
#    Updated: 2024/04/20 04:26:03 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail
SRCS = ft_tail.c ft_tail_print.c ft_tail_utils.c ft_tail_utils2.c ft_tail_errors.c
INCS = .
COMP = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = ft_tail.o ft_tail_print.o ft_tail_utils.o ft_tail_utils2.o ft_tail_errors.o
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