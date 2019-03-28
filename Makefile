# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 02:37:43 by cbagdon           #+#    #+#              #
#    Updated: 2019/03/25 16:58:16 by cbagdon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c \
		error.c \
		flags.c \
		sort.c \
		list.c \
		dir.c \
		display.c \
		sort2.c

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME):
	make -C libft
	@gcc $(FLAGS) -c $(addprefix src/,$(SRC)) -I $(INCLUDES)
	@gcc $(Flags) -o $(NAME) $(OBJECTS) -L ./libft/ -lft

clean:
	make -C libft clean
	@rm -rf $(OBJECTS)

fclean: clean
	make -C libft fclean
	@rm -rf $(NAME)

re: fclean all
