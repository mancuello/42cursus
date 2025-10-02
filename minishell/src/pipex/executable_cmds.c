/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:16:35 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/12 12:17:44 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_initial_pipe(t_token *tokens)
{
	if (tokens && tokens->type == TOKEN_PIPE)
	{
		printf("bash: syntax error near unexpected token `|'\n");
		return (-1);
	}
	return (0);
}

static int	read_more_input(t_token **tokens, char **env)
{
	char	*input;
	t_token	*new_tokens;

	input = readline("> ");
	if (!input)
	{
		printf("\n");
		return (-1);
	}
	if (ft_strlen(input) == 0)
	{
		free(input);
		return (1);
	}
	new_tokens = tokenize(input, env);
	free(input);
	if (!new_tokens)
		return (1);
	append_tokens(tokens, new_tokens);
	return (0);
}

int	executable_cmds(t_token **tokens, char **env)
{
	int	status;

	if (handle_initial_pipe(*tokens) == -1)
		return (-1);
	while (is_last_token_pipe(*tokens))
	{
		status = read_more_input(tokens, env);
		if (status == -1)
			return (-1);
		if (status == 1)
			continue ;
	}
	return (count_cmds(*tokens));
}

/* int	executable_cmds(t_token **tokens, char **env)
{
	t_token	*current;
	t_token	*new_tokens;
	char	*additional_input;
	int		last_token_pipe;

	current = *tokens;
	if (current->type == TOKEN_PIPE)
	{
		printf("bash: syntax error near unexpected token `|'\n");
		return (-1);
	}
	last_token_pipe = is_last_token_pipe(current);
	while (last_token_pipe)
	{
		additional_input = readline("> ");
		if (!additional_input)
		{
			printf("\n");
			return (-1);
		}
		if (ft_strlen(additional_input) == 0)
		{
			free(additional_input);
			continue ;
		}
		new_tokens = tokenize(additional_input, env);
		free(additional_input);
		if (!new_tokens)
			continue ;
		append_tokens(tokens, new_tokens);
		last_token_pipe = is_last_token_pipe(*tokens);
	}
	return (count_cmds(*tokens));
} */
