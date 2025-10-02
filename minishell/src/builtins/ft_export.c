/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:01:36 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/06/15 13:11:01 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_var_name(char *str)
{
	int	i;

	if (!str || !*str || ft_isdigit(*str))
		return (0);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	var_exists(char **env, const char *var)
{
	int		i;
	int		len;

	len = find_equal((char *)var);
	if (len == -1)
		len = ft_strlen(var);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, len) == 0 && env[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

static char	*normalize_export_value(const char *str)
{
	char	*equal_sign;
	char	*name;
	char	*value;
	char	*clean_value;
	char	*result;

	equal_sign = ft_strchr(str, '=');
	if (!equal_sign)
		return (ft_strdup(str));
	name = ft_substr(str, 0, equal_sign - str);
	value = ft_strdup(equal_sign + 1);
	if ((value[0] == '"' && value[ft_strlen(value) - 1] == '"')
		|| (value[0] == '\'' && value[ft_strlen(value) - 1] == '\''))
		clean_value = ft_substr(value, 1, ft_strlen(value) - 2);
	else
		clean_value = ft_strdup(value);
	result = ft_strjoin(name, "=");
	free(name);
	free(value);
	name = result;
	result = ft_strjoin(name, clean_value);
	free(name);
	free(clean_value);
	return (result);
}

void	do_export(t_token *tokens, char ***env)
{
	t_token	*curr;
	int		pos;
	char	*clean_value;

	curr = tokens->next;
	while (curr)
	{
		if (handle_invalid_var(curr->value))
		{
			curr = curr->next;
			continue ;
		}
		clean_value = normalize_export_value(curr->value);
		pos = var_exists(*env, clean_value);
		if (pos >= 0)
			replace_existing_var(env, pos, clean_value);
		else
			add_new_var(env, clean_value);
		free(clean_value);
		curr = curr->next;
	}
}
