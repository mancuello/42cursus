/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:16:59 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/16 16:50:33 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char src[] = "Hello, World!";
	char dest[50];

	ft_memcpy(dest, src, 13);
	printf("Source: %s\n", src);
	printf("Dest: %s\n", dest);
	return (0);
} */
