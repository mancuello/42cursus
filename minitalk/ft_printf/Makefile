# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 14:03:17 by mcuello           #+#    #+#              #
#    Updated: 2025/02/01 16:51:06 by mcuello          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRC			= ft_printf.c\
			  aux1.c\
			  aux2.c\
			  aux3.c

#LIBFT_SRC	= libft/ft_strlen.c

OBJS		= $(SRC:%.c=%.o)

#LIBFT_OBJ	= $(LIBFT_SRC:%.c=%.o)

CC			= cc

CFLAGS		= -Wall -Werror -Wextra

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)
		echo "Library compiled"

clean:
		rm -f $(OBJS)
		echo ".o files removed"

fclean: clean
		rm -f $(NAME)
		echo "Library removed"

re: fclean all

.PHONY: all clean fclean re bonus