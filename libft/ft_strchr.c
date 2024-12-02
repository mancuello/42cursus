/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:24:41 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/02 12:14:32 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
	{
		while (*s && *s != '\0')
			s++;
		return (s);
	}
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}