/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:37:23 by mcuello           #+#    #+#             */
/*   Updated: 2025/02/07 22:54:13 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

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
	while (i < size)
		((char *)reserv)[i++] = '\0';
	return (reserv);
}

/* void	ft_memmove(char *buffer)
{
	size_t	i;
	size_t	pos;

	pos = get_newline_char(buffer);
	i = 0;
	while (buffer[i + pos + 1] != '\0')
	{
		buffer[i] = buffer[i + pos + 1];
		i++;
	}
	while (buffer[i] != '\0')
		buffer[i++] = '\0';
} */

void	ft_copy(char *src, char *dest)
{
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
}

/* char	*ft_concat(char *temp, char *buffer)

{
	char	*temp2;
	size_t	i;
	size_t	j;

	if (!buffer)
		return (temp);
	temp2 = ft_calloc((ft_strlen(temp) + ft_strlen(buffer) + 1), sizeof(char));
	if (!temp2)
		return (0);
	i = 0;
	while (temp[i])
	{
		temp2[i] = temp[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		temp2[i + j] = buffer[j];
		j++;
	}
	free(temp);
	free(buffer);
	return (temp2);
} */


char	*ft_concat(char *temp, char *buffer)
{
	char	*temp2;

	if (!buffer)
		return (temp);
	temp2 = ft_calloc((ft_strlen(temp) + ft_strlen(buffer)) + 1, sizeof(char));
	if (!temp2)
		return (NULL);
	if (temp)
		ft_copy(temp, temp2);
	ft_copy(buffer, temp2);
	return (temp2);
}