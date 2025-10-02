/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:46:34 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/12 13:09:31 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process(t_token *cmd, char **env, int in_fd, int *fd)
{
	if (in_fd != 0)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (fd)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	if (check_redir(cmd))
		do_redir(cmd, env);
	else
		execute_tokens(cmd, env);
	free_tokens(cmd);
	exit(EXIT_FAILURE);
}

void	parent_process(int *in_fd, int *fd, int has_pipe)
{
	if (*in_fd != 0)
		close(*in_fd);
	if (has_pipe)
	{
		close(fd[1]);
		*in_fd = fd[0];
	}
}

void	do_pipes(t_token *tokens, char **env)
{
	pid_t	*pids;
	int		cmds_count;
	int		i;

	cmds_count = executable_cmds(&tokens, env);
	if (cmds_count == -1)
		return ;
	pids = malloc(sizeof(pid_t) * cmds_count);
	if (!pids)
		return ;
	exec_pipeline(tokens, env, pids);
	i = 0;
	while (i < cmds_count)
		waitpid(pids[i++], NULL, 0);
	free(pids);
}

/* void	do_pipes(t_token *tokens, char **env)
{
	pid_t	*pids;
	int		fd[2];
	int		in_fd = 0;
	t_token	*cmd;
	int		i = 0;
	int		j;
	int		cmds_count;

	cmds_count = executable_cmds(&tokens, env);
	if (cmds_count == -1)
		return ;
	pids = malloc(sizeof(pid_t) * cmds_count);

	while (tokens)
	{
		cmd = extract_cmd(&tokens, TOKEN_PIPE);
		if (tokens)
			pipe(fd);
		pids[i] = fork();
		if (!pids[i])
		{
			if (in_fd != 0)
			{
				dup2(in_fd, STDIN_FILENO);
				close(in_fd);
			}
			if (tokens)
			{
				close(fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
			}
			if (check_redir(cmd))
				do_redir(cmd, env);
			else
			 	execute_tokens(cmd, env);
			free_tokens(cmd);
			exit(EXIT_FAILURE);
		}
		else
		{
			if (in_fd != 0)
				close(in_fd);
			if (tokens)
			{
				close(fd[1]);
				in_fd = fd[0];
			}
			i++;
		}
	}
	j = 0;
	while (j < cmds_count)
    	waitpid(pids[j++], NULL, 0);
} */
