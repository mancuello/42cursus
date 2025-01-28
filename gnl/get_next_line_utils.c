/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:37:23 by mcuello           #+#    #+#             */
/*   Updated: 2025/01/28 12:39:19 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t items, size_t size)
{
	void	*reserv;
	size_t	i;

	reserv = malloc(items * size);
	if (!reserv)
		return (NULL);
	i = 0;
	while (i < (items * size))
	{
		*((unsigned char *)(reserv + i)) = (unsigned char)0;
		i++;
	}
	return(reserv);
}

void	ft_bzero(char *buffer, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		buffer[i++] = '\0';
}