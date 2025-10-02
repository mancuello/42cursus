/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:45:06 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/06/15 13:03:35 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_env(char **env, char *input)
{
	char	*p;

	p = input;
	while (*p && !isspace(*p))
		p++;
	while (*p && isspace(*p))
		p++;
	if (*p)
	{
		printf("env: '%s': No such file or directory\n", p);
		g_exit_status = 127;
		return ;
	}
	while (*env)
		printf("%s\n", *env++);
}
