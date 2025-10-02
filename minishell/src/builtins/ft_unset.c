/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:55:24 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/16 08:41:58 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_var(char **env, int index)
{
	int	i;

	i = index;
	free(env[i]);
	while (env[i + 1])
	{
		env[i] = env[i + 1];
		i++;
	}
	env[i] = NULL;
}

void	do_unset(t_token *tokens, char **env)
{
	t_token	*curr;
	int		j;
	int		key_len;

	curr = tokens->next;
	while (curr)
	{
		j = 0;
		key_len = 0;
		while (env[j])
		{
			key_len = find_equal(env[j]);
			if (!ft_strncmp(curr->value, env[j], key_len)
				&& curr->value[key_len] == '\0')
			{
				remove_var(env, j);
				break ;
			}
			j++;
		}
		curr = curr->next;
	}
}
