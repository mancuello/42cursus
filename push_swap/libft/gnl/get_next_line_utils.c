/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:37:23 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/13 00:07:56 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t items, size_t size)
{
	void	*reserv;
	size_t	i;

	reserv = malloc(items * size);
	if (!reserv)
		return (NULL);
	i = 0;
	while (i < (size * items))
		((char *)reserv)[i++] = '\0';
	return (reserv);
}

void	ft_copy(char *src, char *dest)
{
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
}

char	*ft_concat(char **temp, char *buffer)
{
	char	*temp2;

	if (!buffer)
		return (*temp);
	temp2 = ft_calloc((ft_strlen(*temp) + ft_strlen(buffer)) + 1, sizeof(char));
	if (!temp2)
		return (NULL);
	ft_copy(*temp, temp2);
	free(*temp);
	ft_copy(buffer, temp2);
	return (temp2);
}
