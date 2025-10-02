/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:32:17 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/06/12 09:34:11 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_invalid_var(char *value)
{
	if (!is_valid_var_name(value))
	{
		ft_printf("export: `%s': not a valid identifier\n", value);
		return (1);
	}
	return (0);
}

void	replace_existing_var(char ***env, int pos, char *value)
{
	if (ft_strchr(value, '='))
	{
		free((*env)[pos]);
		(*env)[pos] = ft_strdup(value);
	}
}

void	add_new_var(char ***env, char *value)
{
	int		env_size;
	int		j;
	char	**new_env;

	env_size = 0;
	j = 0;
	while ((*env)[env_size])
		env_size++;
	new_env = malloc(sizeof(char *) * (env_size + 2));
	if (!new_env)
		return ;
	while (j < env_size)
	{
		new_env[j] = (*env)[j];
		j++;
	}
	new_env[env_size] = ft_strdup(value);
	new_env[env_size + 1] = NULL;
	free(*env);
	*env = new_env;
}
