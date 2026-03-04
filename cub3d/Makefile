# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:31:23 by mcuello           #+#    #+#              #
#    Updated: 2026/03/03 21:23:44 by mcuello          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

SRC			= main.c \
			  game_loop.c \
			  map.c \
			  get_next_line.c \
			  get_next_line_utils.c \
			  hooks.c \
			  player_moves.c \
			  load_textures.c \

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