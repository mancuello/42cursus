/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:03:08 by mcuello           #+#    #+#             */
/*   Updated: 2025/02/08 14:57:20 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_buffer(int fd, char *buffer, int *i)
{
	static int	bytes_read = 0;

	if (*i < bytes_read)
		return (1);
	*i = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (0);
	buffer[bytes_read] = '\0';
	return (1);
}

char	*process_buffer(int fd, char *temp)
{
	char	*next_line;
	char	*result;

	next_line = get_next_line(fd);
	if (!next_line)
		return (temp);
	result = ft_concat(&temp, next_line);
	free(next_line);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*temp;
	static int	i = 0;
	int			j;

	j = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || !get_buffer(fd, buffer, &i))
		return (0);
	temp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!temp)
		return (0);
	while (ft_strlen(temp) < BUFFER_SIZE && buffer[i] && buffer[i] != '\n')
		temp[j++] = buffer[i++];
	if (buffer[i++] == '\n')
	{
		temp[j] = '\n';
		return (temp);
	}
	else
		return (process_buffer(fd, temp));
}
