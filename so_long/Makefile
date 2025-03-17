# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:31:23 by mcuello           #+#    #+#              #
#    Updated: 2025/03/17 17:15:53 by mcuello          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRC			= main.c \
			  game.c \
			  map.c \
			  get_next_line.c \
			  get_next_line_utils.c \
			  check_map_rules.c \
			  hooks.c \
			  render.c \
			  player_moves.c \
			  sprites.c \
			  ft_error.c \

OBJ			= $(SRC:.c=.o)

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -Iinclude -Imlx

MLX_DIR		= mlx

MLX_LIB		= $(MLX_DIR)/libmlx.a

MLX_FLAGS	= -Lmlx -lmlx -lXext -lX11

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR) --no-print-directory

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean --no-print-directory

re: fclean all