#include "cub3d.h"
#include "get_next_line.h"

static int	check_rectangular(t_map *map)
{
	int	i;
	int	width;

	width = ft_strlen2(map->map[0]);
	i = 1;
	while (i < map->height)
	{
		if (!map->map[i])
			return (-1);
		if (ft_strlen2(map->map[i]) != width)
			return (-1);
		i++;
	}
	map->width = width;
	return (0);
}

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
	if (check_rectangular(map_data) == -1)
	{
		printf("Fallo al leer el mapa.\n");
		return (-1);
	}
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