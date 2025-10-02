/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:26:51 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/16 11:21:28 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redir(t_token *tokens)
{
	int	append;
	int	redir_in;
	int	redir_out;

	append = 0;
	redir_in = 0;
	redir_out = 0;
	while (tokens)
	{
		if (tokens->type == TOKEN_REDIR_APPEND)
			append++;
		else if (tokens->type == TOKEN_REDIR_IN)
			redir_in++;
		else if (tokens->type == TOKEN_REDIR_OUT)
			redir_out++;
		tokens = tokens->next;
	}
	if (redir_in >= 2)
		return (-1);
	if (append || redir_in || redir_out)
		return (1);
	return (0);
}

void	free_redir(t_redir *redirs)
{
	if (redirs->input)
	{
		free(redirs->input);
		redirs->input = NULL;
	}
	if (redirs->output)
	{
		free(redirs->output);
		redirs->output = NULL;
	}
	free(redirs);
}

t_token	*create_token_for_redir(char *value, t_token_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = ft_strdup(value);
	token->type = type;
	token->next = NULL;
	return (token);
}

int	bad_filename(t_token *filename)
{
	if (!ft_strcmp(filename->value, "<")
		|| !ft_strcmp(filename->value, "<<")
		|| !ft_strcmp(filename->value, ">")
		|| !ft_strcmp(filename->value, ">>"))
	{
		printf("bash: syntax error near unexpected token `%s'\n",
			filename->value);
		return (1);
	}
	return (0);
}

t_redir	*create_redir_struct(void)
{
	t_redir	*redir_info;

	redir_info = malloc(sizeof(t_redir));
	redir_info->input = NULL;
	redir_info->output = NULL;
	redir_info->append = 0;
	return (redir_info);
}
