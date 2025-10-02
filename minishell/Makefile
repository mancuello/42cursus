# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 13:25:03 by mcuello           #+#    #+#              #
#    Updated: 2025/06/15 12:21:21 by vboxuser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= minishell

SRC			= main.c\
			  src/parsing/tokenize.c\
			  src/parsing/token_utils.c\
			  src/parsing/expand.c\
			  src/utils/utils.c\
			  src/utils/utils2.c\
			  src/utils/export_utils.c\
			  src/builtins/built.c\
			  src/builtins/ft_echo.c\
			  src/builtins/ft_exit.c\
			  src/builtins/ft_env.c\
			  src/builtins/ft_pwd.c\
			  src/builtins/ft_export.c\
			  src/builtins/ft_cd.c\
			  src/builtins/ft_unset.c\
			  src/builtins/ft_dot.c\
			  src/signal/signal_control.c\
			  src/pipex/pipex.c\
			  src/pipex/pipex_aux.c\
			  src/pipex/init_child.c\
			  src/pipex/executable_cmds.c\
			  src/pipex/exec_pipeline.c\
			  src/redirs/redir.c\
			  src/redirs/redir_aux.c\
			  src/redirs/extrac_clean_cmd.c\
			  src/heredoc/heredoc.c\
			  src/heredoc/heredoc_aux.c\
			  src/heredoc/get_heredoc.c\
			  src/init/init.c\

OBJ			= $(SRC:.c=.o)

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g -Iinclude -I$(LIBFT_DIR) 

LDFLAGS		= -lreadline

LIBFT_DIR	= libft

LIBFT		= $(LIBFT_DIR)/libft.a


all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all