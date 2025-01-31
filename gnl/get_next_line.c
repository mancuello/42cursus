/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:03:08 by mcuello           #+#    #+#             */
/*   Updated: 2025/01/31 16:40:27 by mcuello          ###   ########.fr       */
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

int		get_newline_char(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_copy(char *src, char *dest)
{
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && *src != '\n')
		*dest++ = *src++;
	*dest = '\0';
}

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

void	ft_memmove(char *buffer)
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
}

int	get_buffer(int fd, char *temp, char *buffer)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes_read == -1)
	{
		free(temp);
		temp = NULL;
		return (0);
	}
	if (bytes_read == 0)
	{
		if (temp && temp[0] != '\0')
			return (1);
		return (0);
	}
	return (0);
}


char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	*temp = NULL;
	char		*completed_line = NULL;
	static int	final = 0;

	if (final)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 1)
		return (NULL);
	if (!temp)
	{
		temp = ft_calloc((BUFFER_SIZE), sizeof(char));
		if (!temp)
			return (NULL);
	}
	while (1)
	{
		if (buffer[0] == '\0')
		{
			if (get_buffer(fd, temp, buffer) == 1)
			{
				final = 1;
				return (temp);
			}

		}
		if (get_newline_char(buffer) == -1)
		{
			completed_line = ft_concat(temp, buffer);
			free(temp);
			temp = completed_line;
			buffer[0] = '\0';
		}
		else
		{
			completed_line = ft_concat(temp, buffer);
			free(temp);
			temp = NULL;
			ft_memmove(buffer);
			return (completed_line);
		}
	}
}

int main(int argc, char **argv)
{
    int fd;
    char *line;

    // Verifica que se haya pasado un archivo como argumento
    if (argc != 2)
    {
        printf("Uso: %s <archivo>\n", argv[0]);
        return (1);
    }

    // Abre el archivo en modo solo lectura
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    // Lee el archivo línea por línea usando get_next_line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Sale acá: %s\n", line); // Muestra la línea leída
        free(line); // Libera la memoria de la línea
    }
	if ((line = get_next_line(fd)) == NULL)
		free(line);

    // Cierra el archivo
    close(fd);

    return (0);
}