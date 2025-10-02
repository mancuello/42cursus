/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:24:20 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/06/16 10:08:11 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numeric(const char *str)
{
	size_t	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	do_exit(t_token *tokens)
{
	t_token	*arg;

	arg = tokens->next;
	ft_printf("exit\n");
	if (!arg)
		exit(0);
	if (arg->next)
	{
		ft_printf("bash: too many arguments\n");
		g_exit_status = 1;
		return ;
	}
	if (!is_numeric(arg->value))
	{
		ft_printf("bash: %s: numeric argument required\n", arg->value);
		exit(2);
	}
	exit(ft_atoi(arg->value));
}
