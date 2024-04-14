# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/13 17:41:27 by npentini          #+#    #+#              #
#    Updated: 2024/04/14 15:17:12 by npentini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRCS = ft_display_file.c ft_display_file_utils.c
INCS = .
COMP = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = ft_display_file.o ft_display_file_utils.o
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