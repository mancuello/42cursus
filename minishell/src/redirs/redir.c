/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:41:38 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/16 11:22:14 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_heredoc(t_token *cmd)
{
	int	heredoc_fd;

	if (check_heredoc(cmd))
	{
		heredoc_fd = get_heredoc(cmd);
		if (heredoc_fd == -1)
		{
			perror("heredoc");
			exit(EXIT_FAILURE);
		}
		dup2(heredoc_fd, STDIN_FILENO);
		close(heredoc_fd);
	}
}

static void	handle_input_redir(char *input)
{
	int	fd;

	if (input)
	{
		fd = open(input, O_RDONLY);
		if (fd == -1)
		{
			perror("open input");
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

static void	handle_output_redir(char *output, int flag)
{
	int	fd;

	if (output)
	{
		fd = open(output, O_WRONLY | O_CREAT | flag, 0644);
		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

void	redir_child(t_token *cmd, t_redir *redir_info, char **env)
{
	int	redir_flag;

	if (redir_info->append)
		redir_flag = O_APPEND;
	else
		redir_flag = O_TRUNC;
	handle_heredoc(cmd);
	handle_input_redir(redir_info->input);
	handle_output_redir(redir_info->output, redir_flag);
	free_redir(redir_info);
	execute_tokens(cmd, env);
	free_tokens(cmd);
	exit(EXIT_FAILURE);
}

void	do_redir(t_token *tokens, char **env)
{
	t_token	*cmd;
	t_redir	*redir_info;
	pid_t	pid;

	redir_info = create_redir_struct();
	cmd = extract_clean_cmd(tokens, redir_info);
	if (!cmd)
	{
		free_redir(redir_info);
		return ;
	}
	pid = fork();
	if (!pid)
		redir_child(cmd, redir_info, env);
	else
	{
		waitpid(pid, NULL, 0);
		free_redir(redir_info);
		free_tokens(cmd);
	}
}
