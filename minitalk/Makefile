# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 20:55:03 by mcuello           #+#    #+#              #
#    Updated: 2025/03/31 20:09:46 by mcuello          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		= server
NAME2		= client

SRC1		= server.c

SRC2		= client.c \
			  ft_atoi.c

OBJ1		= $(SRC1:.c=.o)
OBJ2		= $(SRC2:.c=.o)

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	$(CC) $(OBJ1) $(CFLAGS) -o $(NAME1)

$(NAME2): $(OBJ2)
	$(CC) $(OBJ2) $(CFLAGS) -o $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2)

fclean: clean
	rm -f $(NAME1) $(NAME2)

re: fclean all