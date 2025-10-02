/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:32:33 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/16 11:26:24 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_heredoc(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->type == TOKEN_HEREDOC)
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

t_token	*deep_copy_tokens(t_token *tokens)
{
	t_token	*new_list;
	t_token	**current;

	new_list = NULL;
	current = &new_list;
	while (tokens)
	{
		*current = create_token(ft_strdup(tokens->value), tokens->type);
		current = &((*current)->next);
		tokens = tokens->next;
	}
	return (new_list);
}

int	init_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	return (0);
}

int	is_delimiter(char *input, char *delimiter)
{
	if (!ft_strcmp(input, delimiter))
	{
		free(input);
		return (1);
	}
	return (0);
}
