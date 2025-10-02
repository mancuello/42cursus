/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:44:47 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/16 11:16:15 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_child(t_child_args *args)
{
	if (args->tokens)
		child_process(args->cmd, args->env, args->in_fd, args->fd);
	else
		child_process(args->cmd, args->env, args->in_fd, NULL);
}

static void	handle_parent(int *in_fd, int fd[2], t_token *tokens)
{
	if (tokens != NULL)
		parent_process(in_fd, fd, 1);
	else
		parent_process(in_fd, fd, 0);
}

static void	run_pipeline_loop(t_token *tokens, char **env, pid_t *pids)
{
	t_token			*cmd;
	int				fd[2];
	int				in_fd;
	int				i;
	t_child_args	args;

	i = 0;
	in_fd = 0;
	while (tokens)
	{
		cmd = extract_cmd(&tokens, TOKEN_PIPE);
		if (tokens)
			pipe(fd);
		pids[i] = fork();
		if (!pids[i])
		{
			init_child_args_part1(&args, cmd, env, in_fd);
			init_child_args_part2(&args, tokens, fd);
			handle_child(&args);
		}
		else
			handle_parent(&in_fd, fd, tokens);
		free_tokens(cmd);
		i++;
	}
}

void	exec_pipeline(t_token *tokens, char **env, pid_t *pids)
{
	run_pipeline_loop(tokens, env, pids);
}
