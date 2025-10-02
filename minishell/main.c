/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:25:16 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/06/16 08:58:22 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	g_exit_status = 0;

int	main(int argc, char const **argv, char **env)
{
	t_env	*copy_env;

	(void)argv;
	if (argc >= 2)
	{
		printf("Error: Incorrect number of arguments\n");
		return (1);
	}
	init_env(&copy_env, env);
	if (!copy_env)
		return (1);
	return (minishell_loop(copy_env, env));
}
