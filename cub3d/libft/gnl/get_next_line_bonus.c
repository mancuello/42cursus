/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:22:52 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/04/02 09:33:12 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*extract_line(char *remainder)
{
	size_t	i;
	char	*line;

	if (!remainder || *remainder == '\0')
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_remainder(char *remainder)
{
	size_t	i;
	size_t	j;
	char	*new_remainder;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = malloc(ft_strlen_gnl_bonus(remainder) - i + 1);
	if (!new_remainder)
		return (NULL);
	i++;
	j = 0;
	while (remainder[i])
		new_remainder[j++] = remainder[i++];
	new_remainder[j] = '\0';
	free(remainder);
	return (new_remainder);
}

static char	*read_and_append(int fd, char *remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*temp;

	while (!gnl_has_newline_bonus(remainder))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin_gnl_bonus(remainder, buffer);
		if (!temp)
			return (NULL);
		remainder = temp;
	}
	if (bytes_read <= 0 && (!remainder || *remainder == '\0'))
	{
		free(remainder);
		return (NULL);
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainders[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	remainders[fd] = read_and_append(fd, remainders[fd]);
	if (!remainders[fd])
		return (NULL);
	line = extract_line(remainders[fd]);
	remainders[fd] = update_remainder(remainders[fd]);
	return (line);
}
