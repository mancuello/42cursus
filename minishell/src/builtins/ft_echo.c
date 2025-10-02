/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:33:14 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/06/12 13:25:35 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_n_flag(const char *str)
{
	if (!str || str[0] != '-')
		return (0);
	str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str != 'n')
			return (0);
		str++;
	}
	return (1);
}

static void	print_echo(t_token *curr, int newline)
{
	while (curr)
	{
		ft_printf("%s", curr->value);
		if (curr->next)
			ft_printf(" ");
		curr = curr->next;
	}
	if (newline)
		ft_printf("\n");
}

void	do_echo(t_token *tokens)
{
	t_token	*curr;
	int		newline;

	curr = tokens->next;
	newline = 1;
	if (curr && is_n_flag(curr->value))
	{
		newline = 0;
		while (curr && is_n_flag(curr->value))
			curr = curr->next;
	}
	print_echo(curr, newline);
	g_exit_status = 0;
}
