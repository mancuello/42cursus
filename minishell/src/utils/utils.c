/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:21:05 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/06/14 19:30:21 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->next;
		free(tmp->value);
		free(tmp);
	}
}

void	print_tokens(t_token *tokens)
{
	const char	*type_names[] = {
		"WORD", "PIPE", "REDIR_IN",
		"REDIR_OUT", "APPEND", "HEREDOC", "EOF"
	};

	while (tokens)
	{
		dprintf(STDERR_FILENO, "Token [%s] -> Type: %s\n", tokens->value,
			type_names[tokens->type]);
		tokens = tokens->next;
	}
}

void	free_split(char **args)
{
	char	**temp;

	temp = args;
	if (!args)
		return ;
	while (*args)
	{
		free(*args);
		args++;
	}
	free(temp);
}

int	find_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

char	**deep_copy(char **env)
{
	int		i;
	char	**copy;

	i = 0;
	while (env[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (env[i])
	{
		copy[i] = strdup(env[i]);
		if (!copy[i])
		{
			free_split(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
