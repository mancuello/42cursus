/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:43:55 by vboxuser          #+#    #+#             */
/*   Updated: 2025/06/12 13:34:17 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(char **env, const char *key)
{
	int		i;
	int		len;

	if (!key)
		return (NULL);
	len = ft_strlen(key);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], key, len) && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

int	has_unclosed_quotes(const char *input)
{
	char	quote;

	quote = 0;
	while (*input)
	{
		if ((*input == '\'' || *input == '\"') && quote == 0)
			quote = *input;
		else if (*input == quote)
			quote = 0;
		input++;
	}
	return (quote != 0);
}

int	is_only_spaces(const char *str)
{
	while (*str)
	{
		if (!(*str == ' ' || *str == '\t'))
			return (0);
		str++;
	}
	return (1);
}
