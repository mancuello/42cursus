/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:07:21 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/06/11 10:28:51 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*handle_dollar_expression(char *str, int *i, char **env)
{
	char	*value;
	char	*key;
	int		start;

	if (str[*i + 1] == '?')
	{
		*i += 2;
		return (ft_itoa(g_exit_status));
	}
	if (!str[*i + 1] || !(ft_isalpha(str[*i + 1]) || str[*i + 1] == '_'))
	{
		(*i)++;
		return (ft_strdup("$"));
	}
	start = ++(*i);
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	key = ft_substr(str, start, *i - start);
	value = get_env_value(env, key);
	free(key);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}

static char	*handle_regular_char(char c)
{
	char	buf[2];

	buf[0] = c;
	buf[1] = '\0';
	return (ft_strdup(buf));
}

static char	*join_and_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (result);
}

char	*expand_env_variable(char *str, char **env)
{
	int		i;
	char	*result;
	char	*tmp;

	i = 0;
	result = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '$')
			tmp = handle_dollar_expression(str, &i, env);
		else
			tmp = handle_regular_char(str[i++]);
		result = join_and_free(result, tmp);
	}
	free(str);
	return (result);
}
