/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:03:08 by mcuello           #+#    #+#             */
/*   Updated: 2025/01/31 18:18:43 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_newline_char(char *buffer)
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

char	*process_buffer(char **temp, char *buffer)
{
	char	*completed_line;

	completed_line = ft_concat(*temp, buffer);
	free(*temp);
	*temp = completed_line;
	buffer[0] = '\0';
	return (0);
}

char	*process_endline(char **temp, char *buffer)
{
	char	*completed_line;

	completed_line = ft_concat(*temp, buffer);
	free(*temp);
	*temp = NULL;
	ft_memmove(buffer);
	return (completed_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	*temp = NULL;
	static int	final = 0;

	if (final || fd < 0 || BUFFER_SIZE <= 1)
		return (NULL);
	if (!temp)
	{
		temp = ft_calloc((BUFFER_SIZE), sizeof(char));
		if (!temp)
			return (NULL);
	}
	while (1)
	{
		if (buffer[0] == '\0' && get_buffer(fd, temp, buffer) == 1)
			return (final = 1, temp);
		if (get_newline_char(buffer) == -1)
			process_buffer(&temp, buffer);
		else
			return (process_endline(&temp, buffer));
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