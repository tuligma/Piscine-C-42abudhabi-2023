# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 02:27:15 by npentini          #+#    #+#              #
#    Updated: 2024/04/27 02:31:07 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
SRCS = do-op.c do-op_main.c do-op_operations.c do-op_utils.c
INCS = .
COMP = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = do-op.o do-op_main.o do-op_operations.o do-op_utils.o
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