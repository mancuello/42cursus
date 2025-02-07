/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:03:08 by mcuello           #+#    #+#             */
/*   Updated: 2025/02/07 22:55:06 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* int	get_newline_char(char *buffer)
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
} */

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

/* char	*process_buffer(char **temp, char *buffer)
{
	char	*completed_line;

	completed_line = ft_concat(*temp, buffer);
	free(*temp);
	*temp = completed_line;
	buffer[0] = '\0';
	return (0);
} */

/* char	*process_endline(char **temp, char *buffer)
{
	char	*completed_line;

	completed_line = ft_concat(*temp, buffer);
	free(*temp);
	*temp = NULL;
	ft_memmove(buffer);
	return (completed_line);
} */

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
		return(temp);
	else
		return (ft_concat(temp, get_next_line(fd)));
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