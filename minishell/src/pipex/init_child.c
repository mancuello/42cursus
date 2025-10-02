/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:01:21 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/12 13:08:11 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_child_args_part1(t_child_args *args, t_token *cmd,
		char **env, int in_fd)
{
	args->cmd = cmd;
	args->env = env;
	args->in_fd = in_fd;
}

void	init_child_args_part2(t_child_args *args, t_token *tokens,
		int fd[2])
{
	args->tokens = tokens;
	args->fd[0] = fd[0];
	args->fd[1] = fd[1];
}
