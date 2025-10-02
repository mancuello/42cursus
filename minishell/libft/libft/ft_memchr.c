/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:05:43 by marvin            #+#    #+#             */
/*   Updated: 2025/03/12 09:44:07 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	v;

	i = 0;
	p = (unsigned char *)ptr;
	v = (unsigned char)value;
	while (i < num)
	{
		if (p[i] == v)
		{
			return (&p[i]);
		}
		i++;
	}
	return (NULL);
}
