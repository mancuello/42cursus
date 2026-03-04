/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:46:33 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/04/02 09:34:55 by haxpe-ga         ###   ########.fr       */
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
	new_remainder = malloc(ft_strlen_gnl(remainder) - i + 1);
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

	while (!gnl_has_newline(remainder))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin_gnl(remainder, buffer);
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
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_and_append(fd, remainder);
	if (!remainder)
		return (NULL);
	line = extract_line(remainder);
	remainder = update_remainder(remainder);
	return (line);
}

/* int main(void)
{
    int fd = open("42_with_nl", O_RDONLY);
    char *line;

    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
} */

/* int main(void)
{
    int fd;             // Descriptor del archivo
    char *line;         // Línea leída con get_next_line

    // Abre el archivo en modo solo lectura
    fd = open("multiple_nlx5", O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return (1);
    }
    // Llama a get_next_line en un bucle y muestra cada línea
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Libera la memoria de la línea leída
    }
    // Cierra el archivo
    close(fd);
    return (0);
} */

/* void test_get_next_line(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error abriendo el archivo");
        return;
    }

    printf("=== Probando archivo: %s ===\n", filename);
    char *line = get_next_line(fd);
    while (line)
    {
        printf("Línea: %s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    printf("=== Fin de prueba para: %s ===\n\n", filename);
}
int main(void)
{
    // Caso 1: Archivo normal con varias líneas
    test_get_next_line("test.txt");

    // Caso 2: Archivo vacío
    test_get_next_line("vacio.txt");

    // Caso 3: Archivo sin saltos de línea
    test_get_next_line("testsinsalto.txt");

    // Caso 4: Archivo con un único salto de línea
    test_get_next_line("testunsalto.txt");

    // Caso 5: Descriptor de archivo inválido
    printf("=== Probando descriptor de archivo inválido ===\n");
    char *line = get_next_line(-1);
    if (!line)
        printf("Resultado esperado: NULL para descriptor inválido.\n");
    free(line);

    return 0;
} */