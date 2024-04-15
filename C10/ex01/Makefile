# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 12:17:04 by npentini          #+#    #+#              #
#    Updated: 2024/04/15 12:18:15 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
SRCS = ft_cat.c ft_cat_print.c ft_cat_utils.c
INCS = .
COMP = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = ft_cat.o ft_cat_print.o ft_cat_utils.o
DELETE = rm -f

all: $(NAME)

%.o : %.c
	$(COMP) $(CFLAGS) -I $(INCS) -c $< -o $@

$(NAME) : $(OBJS)
	$(COMP) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(DELETE) $(OBJS)

fclean: clean
	$(DELETE) $(NAME)

re: clean fclean

.PHONY: all clean fclean re