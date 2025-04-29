/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:52:51 by mcuello           #+#    #+#             */
/*   Updated: 2025/02/05 12:57:09 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_conv(int c)
{
	ft_putchar(c);
	return (1);
}

int	ft_putstr2(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	free(s);
	return (i);
}

int	s_conv(char *s)
{
	int	i;

	if (!s)
		return (s_conv("(null)"));
	i = 0;
	while (s && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
