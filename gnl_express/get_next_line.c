/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:41:56 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/25 17:52:39 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *line)
{
	char	*dest;
	int		i;

	i = 0;
	while (line[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (line[i])
	{
		dest[i] = line[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	line[700000];
	int		readed;
	int		index;
	int		i;

	i = 0;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	while (1)
	{
		if (index >= readed)
		{
			readed = read(fd, buffer, BUFFER_SIZE);
			index = 0;
			if (readed <= 0)
				break ;
		}
		line[i++] = buffer[index++];
		if (line[i - 1] == '\n')
			break ;
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (!fd)
	{
		perror("error");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("sale aca ==> %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
