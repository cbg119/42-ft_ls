# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/05 15:29:10 by cbagdon           #+#    #+#              #
#    Updated: 2019/03/05 23:49:54 by cbagdon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c \
	  list.c

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME):
	make -C libft
	gcc -g $(FLAGS) -c $(addprefix src/,$(SRC)) -I $(INCLUDES)
	gcc -g $(FLAGS) -o $(NAME) $(OBJECTS) -L ./libft/ -lft

clean:
	make -C libft clean
	rm -rf $(OBJECTS)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
