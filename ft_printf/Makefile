# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 14:03:17 by mcuello           #+#    #+#              #
#    Updated: 2025/01/10 17:24:54 by mcuello          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRC			= ft_printf.c\
			  aux.c\
			  aux2.c\
			  aux3.c

OBJS		= $(SRC:%.c=%.o)

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

.c.o: $(SRC)
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

re: fclean $(NAME)

.PHONY: all clean fclean re bonus