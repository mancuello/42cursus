/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:10:16 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/06/14 19:44:26 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_metacharacter(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == ' ');
}

static char	*extract_quoted_word(char **input, char quote, char **env)
{
	char	*start;
	char	*word;

	start = ++(*input);
	while (**input && **input != quote)
		(*input)++;
	if (**input != quote)
		return (NULL);
	word = ft_substr(start, 0, *input - start);
	(*input)++;
	if (quote == '\"')
		word = expand_env_variable(word, env);
	return (word);
}

static t_token	*process_token(char **input, char **env)
{
	char	*word;

	if (**input == '|')
	{
		(*input)++;
		return (create_token(ft_strdup("|"), TOKEN_PIPE));
	}
	else if (**input == '<' || **input == '>')
	{
		return (handle_redirection_2(input));
	}
	else if (**input == '\'' || **input == '\"')
	{
		word = extract_quoted_word(input, **input, env);
		return (create_token(word, TOKEN_WORD));
	}
	else
	{
		word = extract_word(input);
		word = expand_env_variable(word, env);
		return (create_token(word, TOKEN_WORD));
	}
}

static bool	tokenize_loop(char *input, char **env, t_token *head)
{
	t_token	*curr;

	curr = head;
	while (*input)
	{
		skip_spaces(&input);
		if (!*input)
			break ;
		curr->next = process_token(&input, env);
		if (!curr->next || !curr->next->value)
		{
			free_tokens(head->next);
			return (false);
		}
		curr = curr->next;
	}
	return (true);
}

t_token	*tokenize(char *input, char **env)
{
	t_token	head;

	head.value = NULL;
	head.type = TOKEN_EOF;
	head.next = NULL;
	if (!tokenize_loop(input, env, &head))
		return (NULL);
	return (head.next);
}

/* t_token	*tokenize(char *input, char **env)
{
	t_token	head;
	t_token	*curr;

	head.value = NULL;
	head.type = TOKEN_EOF;
	head.next = NULL;
	curr = &head;

	while (*input)
	{
		skip_spaces(&input);
		if (!*input)
			break ;
		curr->next = process_token(&input, env);
		if (!curr->next || !curr->next->value)
		{
			free_tokens(head.next);
			return (NULL);
		}
		if (!curr->next->value)
		{
			free_tokens(head.next);
			return (NULL);
		}
		curr = curr->next;
	}
	return (head.next);
} */
