# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/13 17:49:10 by mcuello           #+#    #+#              #
#    Updated: 2025/04/13 18:14:58 by mcuello          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRC				=

OBJ				= $(SRC:.c=.o)

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

FT_PRINTF_DIR	= ft_printf

FT_PRINTF		= $(FT_PRINTF_DIR)/libftprintf.a

all: $(FT_PRINTF) $(NAME)

$(FT_PRINTF)
	@make -C $(FT_PRINTF_DIR) --no-print-directory

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_PRINTF) -o $(NAME)

%.c= %.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	make -C $(FT_PRINTF_DIR) fclean --no-print-directory 
	rm -f $(NAME)

re: fclean all