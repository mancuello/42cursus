/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:47:15 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/07 18:45:47 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && (str[i] != '\0' && str[i] != '\n'))
		i++;
	return (i);
}

/* static int check_rectangular(t_map *map)
{
	int		i;
	int		width;

	width = ft_strlen(map->map[0]);
	i = 1;
	while (i < map->height)
	{
		if (ft_strlen(map->map[i]) != width)
			return (-1);
		i++;
	}
	map->width = width;
	return (0);
} */
static int check_rectangular(t_map *map)
{
	int i;
	int width;
	width = ft_strlen(map->map[0]);
	i = 1;
	while (i < map->height)
	{
		if (!map->map[i])
			return (-1);
		if (ft_strlen(map->map[i]) != width)
			return (-1);
		i++;
	}
	map->width = width;
	return (0);
}


static int check_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

static int	check_elements(t_map *map)
{
	int	i;
	int	j;

	map->player_count = 0;
	map->collect_count = 0;
	map->exit_count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				map->player_count++;
			else if (map->map[i][j] == 'C')
				map->collect_count++;
			else if (map->map[i][j] == 'E')
				map->exit_count++;
			j++;
		}
		i++;
	}
	if (map->player_count != 1 || map->collect_count < 1 || map->exit_count != 1)
		return (-1);
	return (0);
}

int	check_map_rules(t_map *map)
{
	if (!map || !map->map)
        return (-1);
	if (check_rectangular(map) == -1)
		return (-1);
	if (check_borders(map) == -1)
		return (-1);
	if (check_elements(map) == -1)
		return (-1);
	return (0);
}

//para pruebas cambiar los valores comprobados en los if
