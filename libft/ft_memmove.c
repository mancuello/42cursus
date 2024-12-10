/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:36:59 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/10 18:08:32 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n;
	if (!dest || !src || !n)
		return (0);
	if (dest == src)
		return (dest);
	else if (dest > src)
	{
		while (i--)
			((char *)dest)[i] = ((char *)src)[i];
		return (dest);
	}
	else
		return (ft_memcpy(dest, src, n));
}
