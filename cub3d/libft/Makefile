# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 09:29:32 by haxpe-ga          #+#    #+#              #
#    Updated: 2025/05/15 16:53:46 by mcuello          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_calloc.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_itoa.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_putchar_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_split.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c \
		libft/ft_striteri.c \
		libft/ft_strjoin.c \
		libft/ft_strlcat.c \
		libft/ft_strlcpy.c \
		libft/ft_strlen.c \
		libft/ft_strmapi.c \
		libft/ft_strncmp.c \
		libft/ft_strcmp.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_strtrim.c \
		libft/ft_substr.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_hex.c \
		ft_printf/ft_printf_put.c \
		gnl/get_next_line_bonus.c \
		gnl/get_next_line_utils_bonus.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./libft

AR = ar rc
RM = rm -f

# Librería libft
LIBFT_DIR = ./libft

# *****************************************************************************************

all: $(NAME)

$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
