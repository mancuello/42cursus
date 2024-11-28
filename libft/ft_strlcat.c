/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:16:42 by mcuello           #+#    #+#             */
/*   Updated: 2024/11/28 18:01:33 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	i;
	size_t	rvalue;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	else if (size <= ft_strlen(dest))
		rvalue = ft_strlen(src) + size;
	else
		rvalue = ft_strlen(src) + ft_strlen(dest);
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (rvalue);
}
