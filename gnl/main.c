/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:51:45 by mcuello           #+#    #+#             */
/*   Updated: 2025/02/11 13:44:50 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

    // Lee el archivo línea por línea
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Sale acá: %s", line);
        free(line);
    }
	if ((line = get_next_line(fd)) == NULL)
		free(line);

    close(fd);

    return (0);
}