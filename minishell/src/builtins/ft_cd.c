/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:56:09 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/06/12 09:26:38 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* void	do_cd(char *input, char **env)
{
	char	**args;
	char	*home_path;

	home_path = get_env_value(env, "HOME");
	args = ft_split(input, ' ');
	if (!args[1])
		chdir(home_path);
	else if (args[2])
		printf("Demasiados argumentos.\n");
	else
	{
		if (chdir(args[1]))
		{
			printf("El directorio no existe.\n");
			g_exit_status = 1;
		}
		else
			g_exit_status = 0;
	}
	free_split(args);
} */

void	do_cd(t_token *tokens, char **env)
{
	char	*home_path;
	t_token	*arg;

	home_path = get_env_value(env, "HOME");
	arg = tokens->next;
	if (!arg)
		chdir(home_path);
	else if (arg->next)
		printf("cd: too many arguments\n");
	else if (chdir(arg->value))
	{
		printf("cd: %s: No such file or directory\n", arg->value);
		g_exit_status = 1;
	}
	else
		g_exit_status = 0;
}
