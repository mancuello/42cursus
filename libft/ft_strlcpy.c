/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:41:46 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/17 16:03:18 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (src[counter])
		counter++;
	while (src[i] && (i + 1 < size))
	{
		dest[i] = src[i];
		i++;
	}
	if (size)
		dest[i] = '\0';
	return (counter);
}
