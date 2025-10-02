/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:19:24 by vboxuser          #+#    #+#             */
/*   Updated: 2025/06/15 12:20:16 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_dot(t_token *tokens)
{
	if (!tokens->next || !tokens->next->value)
	{
		printf(".: filename argument required\n");
		printf(".: usage: . filename [arguments]\n");
		g_exit_status = 2;
		return ;
	}
	if (access(tokens->next->value, F_OK) != 0)
	{
		perror(tokens->next->value);
		g_exit_status = 1;
		return ;
	}
	if (access(tokens->next->value, R_OK) != 0)
	{
		perror(tokens->next->value);
		g_exit_status = 1;
		return ;
	}
	printf(".: executing script is not supported yet\n");
	g_exit_status = 0;
}
