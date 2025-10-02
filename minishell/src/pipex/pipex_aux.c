/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:19:26 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/16 11:15:39 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmds(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens)
	{
		if (tokens->type == TOKEN_PIPE)
			i++;
		tokens = tokens->next;
	}
	return (++i);
}

int	is_last_token_pipe(t_token *tokens)
{
	while (tokens->next)
		tokens = tokens->next;
	if (tokens->type == TOKEN_PIPE)
		return (1);
	return (0);
}

void	append_tokens(t_token **head, t_token *new_tokens)
{
	t_token	*last;

	last = *head;
	while (last->next)
		last = last->next;
	last->next = new_tokens;
}

int	check_pipes(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->type == TOKEN_PIPE)
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

t_token	*extract_cmd(t_token **tokens, t_token_type TOKEN_TYPE)
{
	t_token	*current;
	t_token	*cmd;
	t_token	*new_node;
	t_token	*head;

	head = NULL;
	cmd = NULL;
	current = *tokens;
	while (current && current->type != TOKEN_TYPE)
	{
		new_node = create_token_for_redir(current->value, current->type);
		if (!head)
			head = new_node;
		else
			cmd->next = new_node;
		cmd = new_node;
		current = current->next;
	}
	if (current && current->type == TOKEN_TYPE)
		*tokens = current->next;
	else
		*tokens = NULL;
	return (head);
}
