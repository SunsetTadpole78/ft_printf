# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 17:54:50 by lroussel          #+#    #+#              #
#    Updated: 2024/11/15 21:25:36 by lroussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src
INCLUDE = include
DEFAULT = ft_printf.c	\
	  mapper.c	\
	  printer.c	\
	  counters.c
FILES = $(addprefix $(SRC)/, $(DEFAULT))
OBJS = $(FILES:%.c=%.o)
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

bonus: $(NAME)

%.o: %.c
	cc $(FLAGS) $< -c -o $@ -I $(INCLUDE)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
