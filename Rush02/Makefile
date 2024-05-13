# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 19:44:18 by npentini          #+#    #+#              #
#    Updated: 2024/05/14 02:56:13 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
SRCS = rush02_argv.c rush02_print.c rush02_main.c rush02_parse.c rush02_table.c rush02_data_insertion.c rush02_data_insertion2.c rush02_search.c rush02_search_print.c 
INCS = .
COMP = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = rush02_argv.o rush02_print.o rush02_main.o rush02_parse.o rush02_table.o rush02_data_insertion.o rush02_data_insertion2.o rush02_search.o rush02_search_print.o
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