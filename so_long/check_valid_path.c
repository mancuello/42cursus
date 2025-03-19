/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:57:28 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/19 17:09:08 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	fill(char **map, char to_find, int y, int x)
{
	int	i;

	if (y < 0 || x < 0 || !map[y] || !map[y][x])
		return (0);
	if (map[y][x] == 'F' || map[y][x] == '1')
		return (0);
	i = (map[y][x] == to_find || map[y][x] == 'E');
	map[y][x] = 'F';
	i += fill(map, to_find, y + 1, x);
	i += fill(map, to_find, y - 1, x);
	i += fill(map, to_find, y, x - 1);
	i += fill(map, to_find, y, x + 1);
	return (i);
}

static int	find_player_pos(t_map *map, t_pos *player_pos)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				player_pos->y = y;
				player_pos->x = x;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

static void	deep_copy(t_map *map, t_map *copy_map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		copy_map->map[y] = malloc(sizeof(char) * (map->width));
		if (!copy_map->map[y])
			return ;
		x = 0;
		while (x < map->width)
		{
			copy_map->map[y][x] = map->map[y][x];
			x++;
		}
		y++;
	}
}

int	check_valid_path(t_map *map)
{
	t_map	copy_map;
	t_pos	player_pos;

	copy_map.height = map->height;
	if (find_player_pos(map, &player_pos) == -1)
		return (-1);
	copy_map.map = malloc(sizeof(char *) * (map->height));
	deep_copy(map, &copy_map);
	if (fill(copy_map.map, 'C', player_pos.y, player_pos.x)
		!= map->collect_count + 1)
		return (free_map(&copy_map), -1);
	free_map(&copy_map);
	return (0);
}
