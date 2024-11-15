# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 17:54:50 by lroussel          #+#    #+#              #
#    Updated: 2024/11/15 16:36:03 by lroussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT = ft_printf.c	\
	  printer.c	\
	  counters.c
OBJS = $(DEFAULT:%.c=%.o)
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)


%.o: %.c
	gcc $< -c -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	clear
	gcc  $(DEFAULT) main.c -L. -lftprintf -g
	./a.out

.PHONY: all clean fclean re
