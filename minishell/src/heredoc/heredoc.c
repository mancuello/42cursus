/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 23:36:06 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/16 11:30:20 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_input_loop(int write_fd, char *delimiter)
{
	char	*input;

	while (1)
	{
		input = readline("> ");
		if (!input)
		{
			printf("warning: heredoc delimited by end-of-file\n");
			break ;
		}
		if (is_delimiter(input, delimiter))
			break ;
		write(write_fd, input, ft_strlen(input));
		write(write_fd, "\n", 1);
		free(input);
	}
	return (0);
}

int	read_input(char *delimiter)
{
	int	pipe_fd[2];

	if (init_pipe(pipe_fd) == -1)
		return (-1);
	handle_input_loop(pipe_fd[1], delimiter);
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}

static int	check_syntax_and_prepare(t_token **tokens, t_token **cmd)
{
	*cmd = extract_cmd(tokens, TOKEN_HEREDOC);
	if (!*tokens)
	{
		printf("syntax error near unexpected token.\n");
		return (0);
	}
	return (1);
}

static pid_t	execute_with_heredoc(int fd_read, t_token *cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd_read, STDIN_FILENO);
		close(fd_read);
		execute_tokens(cmd, env);
		free_tokens(cmd);
		exit(EXIT_FAILURE);
	}
	else
		close(fd_read);
	return (pid);
}

void	do_main_heredoc(t_token *tokens, char **env)
{
	t_token	*cmd;
	int		fd_read;
	pid_t	pid;

	cmd = NULL;
	if (!check_syntax_and_prepare(&tokens, &cmd))
		return ;
	fd_read = get_heredoc(tokens);
	tokens = tokens->next;
	if (!cmd)
		cmd = deep_copy_tokens(tokens);
	if (fd_read == -1 || !cmd)
	{
		free_tokens(cmd);
		return ;
	}
	pid = execute_with_heredoc(fd_read, cmd, env);
	waitpid(pid, NULL, 0);
	free_tokens(cmd);
}

/* void	do_main_heredoc(t_token *tokens, char **env)
{
	t_token	*cmd;
	int		fd_read;
	pid_t	pid;

	cmd = extract_cmd(&tokens, TOKEN_HEREDOC);
	if (!tokens)
	{
		printf("syntax error near unexpected token.\n");
		return ;
	}
	fd_read = get_heredoc(tokens);
	tokens = tokens->next;
	if (!cmd)
		cmd = deep_copy_tokens(tokens);
	if (fd_read == -1)
		return ;
	if (!cmd)
		return ;
	pid = fork();
	if (pid == 0)
	{
		dup2(fd_read, STDIN_FILENO);
		close(fd_read);
		execute_tokens(cmd, env);
		free_tokens(cmd);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(fd_read);
		waitpid(pid, NULL, 0);
	}
	free_tokens(cmd);
} */
