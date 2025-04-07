# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 20:55:03 by mcuello           #+#    #+#              #
#    Updated: 2025/04/07 15:38:48 by mcuello          ###   ########.fr        #
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

CFLAGS		= -Wall -Wextra -Werror -I$(FT_PRINTF_DIR)

FT_PRINTF_DIR = ft_printf

FT_PRINTF	= $(FT_PRINTF_DIR)/libftprintf.a


all: $(FT_PRINTF) $(NAME1) $(NAME2)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR) --no-print-directory

$(NAME1): $(OBJ1)
	$(CC) $(OBJ1) $(FT_PRINTF) -o $(NAME1)

$(NAME2): $(OBJ2)
	$(CC) $(OBJ2) $(FT_PRINTF) -o $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2)

fclean: clean
	rm -f $(NAME1) $(NAME2)
	make -C $(FT_PRINTF_DIR) fclean --no-print-directory

re: fclean all