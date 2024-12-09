/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:58:47 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/06 22:58:47 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	cc;
	size_t				i;

	s = (unsigned char *)str;
	cc = c;
	i = 0;
	while (i < n)
		if (s[i++] == cc)
			return (s + i - 1);
	return (0);
}