# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 19:44:18 by npentini          #+#    #+#              #
#    Updated: 2024/05/08 04:21:48 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
SRCS = rush02_main.c rush02_utils.c rush02_utils2.c rush02_print.c rush02_argv.c
INCS = .
COMP = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = rush02_main.o rush02_utils.o rush02_utils2.o rush02_print.o rush02_argv.o
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