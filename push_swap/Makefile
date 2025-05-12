# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/13 17:49:10 by mcuello           #+#    #+#              #
#    Updated: 2025/05/12 23:56:05 by mcuello          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

BONUS			= checker

SRC				= list_handler.c\
				  list_handler_aux.c\
				  parsing.c\
				  normalization.c\
				  rotations.c\
				  turkish_sort.c\
				  turkish_sort_aux.c\
				  push_swap.c\
				  radix_sort.c\
				  quick_sort.c\
				  aux.c\

BONUS_SRC		= checker.c\
				  list_handler_aux.c\
				  list_handler.c\
				  parsing.c\
				  normalization.c\
				  rotations.c\
				  turkish_sort.c\
				  turkish_sort_aux.c\
				  radix_sort.c\
				  quick_sort.c\
				  aux.c\

OBJ				= $(SRC:.c=.o)

BONUS_OBJ		= $(BONUS_SRC:.c=.o)

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

LIBFT_DIR		= libft

LIBFT			= $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory


$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I libft/include -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) $(LIBFT) -o $(BONUS)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean --no-print-directory 
	rm -f $(NAME) $(BONUS)

re: fclean all