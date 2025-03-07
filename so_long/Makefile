# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:31:23 by mcuello           #+#    #+#              #
#    Updated: 2025/02/27 19:54:36 by mcuello          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC		= main.c \
		  game.c \
		  player.c \
		  map.c \
		  get_next_line.c \
		  get_next_line_utils.c \
		  check_map_rules.c

OBJ		= $(SRC:.c=.o)

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -I include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -L/usr/local/lib -lmlx -lXext -lX11

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all