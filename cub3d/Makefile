# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:31:23 by mcuello           #+#    #+#              #
#    Updated: 2026/03/05 15:34:50 by mcuello          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

SRC			= main.c \
			  extension_rules.c \
			  fd_parser.c \
			  map.c \
			  game_loop.c \
			  hooks.c \
			  player_moves.c \
			  load_textures.c \
			  get_next_line.c \
			  get_next_line_utils.c \

OBJ			= $(SRC:.c=.o)

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -Iinclude -Imlx -Ilibft

MLX_DIR		= mlx

MLX_LIB		= $(MLX_DIR)/libmlx.a

MLX_FLAGS	= -Lmlx -lmlx -lXext -lX11

LIB_DIR		= libft

LIB		= $(LIB_DIR)/libft.a

all: $(LIB) $(MLX_LIB) $(NAME)

$(LIB):
	@make -C $(LIB_DIR) --no-print-directory

$(MLX_LIB):
	@make -C $(MLX_DIR) --no-print-directory

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L$(LIB_DIR) -lft $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean --no-print-directory
	make -C $(LIB_DIR) clean --no-print-directory

re: fclean all