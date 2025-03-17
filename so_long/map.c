/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:12:57 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/17 19:25:52 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static int	count_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	read_map(char *filename, t_map *map_data)
{
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	map_data->height = count_lines(fd);
	if (map_data->height == 0)
		return (-1);
	fd = open(filename, O_RDONLY);
	map_data->map = malloc(sizeof(char *) * (map_data->height + 1));
	if (!map_data->map)
		return (-1);
	i = 0;
	while (i < map_data->height)
	{
		map_data->map[i] = get_next_line(fd);
		if (!map_data->map[i])
			return (-1);
		i++;
	}
	map_data->map[i] = NULL;
	close(fd);
	printf("Mapa leído correctamente.\n");
	return (0);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map->map)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
}

//lo que hacemos aqui es leer el mapa y formarlo. leemos linea
//por linea para saber la altura luego en cada instancia almacenamos
//el puntero que nos dirije a la linea.