/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:03:08 by mcuello           #+#    #+#             */
/*   Updated: 2025/01/26 19:24:43 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

#define BUFFER_SIZE 42

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

int		get_newline_char(char *buffer)
{
	size_t	i;

	i = 0;
	while (i < (ft_strlen(buffer) - 1))
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
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


char	*ft_concat(char *first, char *second, int start_second)
{
	char	*temp2;
	int		i;
	int		j;
	
	i = 0;
	j = start_second;
	if (!second)
		return (first);	
	temp2 = ft_calloc((ft_strlen(first) + ft_strlen(second)), sizeof(char));
	if (!temp2)
		return (NULL);
	if (ft_strlen(first) != 0)
	{
		while (first[i] != '\0')
		{
			temp2[i] = first[i];
			i++;
		}
		free(first);
		first = NULL;
	}
	while(second[j] != '\0')
	{
		temp2[i++] = second[j++];
	}
	temp2[i] = '\0';
	return (temp2);
}

void	ft_bzero(char *buffer, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		buffer[i++] = '\0';
}


char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	*temp = NULL;
	char		*completed_line = NULL;
	int			bytes_read;
	int			pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!temp)
	{
		temp = ft_calloc((BUFFER_SIZE), sizeof(char));
		if (!temp)
			return (NULL);
		temp[BUFFER_SIZE - 1] = '\0';
	}
	while (1)
	{
		if (buffer[0] == '\0')
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
			if (bytes_read == -1)
			{
				free(temp);
				temp = NULL;
				return (NULL);
			}
			if (bytes_read == 0)
			{
				break;
			}
			//buffer[bytes_read] = '\0';
		}
		pos = get_newline_char(buffer);
		if (pos == -1)
		{
			temp = ft_concat(temp, buffer, 0);
			ft_bzero(buffer, BUFFER_SIZE);
		}
		else
		{
			completed_line = ft_concat(temp, buffer, 0);
			temp = ft_concat(NULL, buffer, pos + 1);
			ft_bzero(buffer, BUFFER_SIZE);
			return (completed_line);
		}
	}
	if (temp && temp[0] != '\0')
	{
		completed_line = temp;
		temp = NULL;
		return (completed_line);
	}
	free(temp);
	temp = NULL;
	return (NULL);
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

    // Cierra el archivo
    close(fd);

    return (0);
}