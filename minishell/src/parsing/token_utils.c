/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:49:20 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/06/14 15:18:52 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	skip_spaces(char **input)
{
	while (**input == ' ')
		(*input)++;
}

t_token	*create_token(char *value, t_token_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = value;
	token->type = type;
	token->next = NULL;
	return (token);
}

t_token	*handle_redirection_2(char **input)
{
	if (**input == '<')
	{
		(*input)++;
		if (**input == '<')
			return ((*input)++, create_token(ft_strdup("<<"), TOKEN_HEREDOC));
		else
			return (create_token(ft_strdup("<"), TOKEN_REDIR_IN));
	}
	else
	{
		(*input)++;
		if (**input == '>')
			return ((*input)++, create_token(ft_strdup(">>"),
					TOKEN_REDIR_APPEND));
		else
			return (create_token(ft_strdup(">"), TOKEN_REDIR_OUT));
	}
}

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

char	*extract_word(char **input)
{
	char	*start;
	char	*word;
	char	quote;
	int		i;

	start = *input;
	i = 0;
	while ((*input)[i] && !is_metacharacter((*input)[i])
			&& !ft_isspace((*input)[i]))
	{
		if ((*input)[i] == '\'' || (*input)[i] == '"')
		{
			quote = (*input)[i++];
			while ((*input)[i] && (*input)[i] != quote)
				i++;
			if ((*input)[i])
				i++;
		}
		else
			i++;
	}
	word = ft_substr(start, 0, i);
	*input += i;
	return (word);
}
