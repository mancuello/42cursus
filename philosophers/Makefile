# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 21:56:55 by mcuello           #+#    #+#              #
#    Updated: 2025/07/21 21:13:43 by mcuello          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRC			= main.c\
			  src/philo.c\
			  src/ft_atoi.c\
			  src/aux.c\
			  src/threads.c\
			  src/routine.c\
			  src/init.c\
			  src/monitor.c\

OBJ			= $(SRC:.c=.o)

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -Iinclude -g


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lpthread -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all