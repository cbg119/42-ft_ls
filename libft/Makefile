# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 16:50:18 by cbagdon           #+#    #+#              #
#    Updated: 2019/03/15 23:44:10 by cbagdon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_strcpy.c \
	   ft_strdup.c \
	   ft_strlen.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isupper.c \
	   ft_islower.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_getwordcount.c \
	   ft_strsplit.c \
	   ft_intlen.c \
	   ft_itoa.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstpush.c \
	   ft_lstmap.c \
	   ft_strccpy.c \
	   get_next_line.c \
	   ft_strndup.c \
	   ft_stroverlap.c \
	   ft_strmove.c \
	   ft_strrev.c

PRINTF_SRCS = decision.c \
			  dispatch_array.c \
			  ft_printf.c \
			  options.c \
			  utils.c

PRINTF_CONVERSIONS = convert_c.c \
					 convert_f.c \
					 convert_i.c \
					 convert_o.c \
					 convert_p.c \
					 convert_percent.c \
					 convert_s.c \
					 convert_u.c \
					 convert_x.c \
					 convert_xl.c

PRINTF_EXTRAS = ft_imsorry.c \
				ft_intmove.c \
				ft_numlen.c \
				ft_pad.c \
				pf_putfloat.c

OBJECTS = $(patsubst %.c,%.o,$(SRCS))
OBJECTS += $(patsubst %.c,%.o,$(PRINTF_SRCS))
OBJECTS += $(patsubst %.c,%.o,$(PRINTF_CONVERSIONS))
OBJECTS += $(patsubst %.c,%.o,$(PRINTF_EXTRAS))

INCLUDES = includes/

all:	$(NAME)

$(NAME):
	gcc -g -Wall -Wextra -Werror -I includes/libft.h -c $(addprefix srcs/,$(SRCS)) $(addprefix ft_printf/src/,$(PRINTF_SRCS)) $(addprefix ft_printf/conversions/,$(PRINTF_CONVERSIONS)) $(addprefix ft_printf/extras/,$(PRINTF_EXTRAS))
	ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
