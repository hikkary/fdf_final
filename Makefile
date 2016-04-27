# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/27 22:26:59 by zkerkeb           #+#    #+#              #
#    Updated: 2016/03/27 23:10:41 by zkerkeb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = 	data.c\
		fdf.c\
		get_next_line.c\
		graph.c\
		stoi.c\
		us_func.c\

DOTO	=		$(SRC:.c=.o)

FW = -lmlx -framework OpenGL -framework AppKit

FLAGS	= -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(DOTO)
	make -C libft
	gcc $(FLAGS) $(FW) -lft -L ./libft -o $(NAME) $(DOTO)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	make -C libft/ fclean
	rm -rf $(DOTO)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
