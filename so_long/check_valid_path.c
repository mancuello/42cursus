/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:57:28 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/18 17:50:09 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	fill(char **map, char to_find, int y, int x)
{
	int i;

	if(map[y][x] == 'F' || map[y][x] = '1')
		return (0);
	i = (map[y][x] == to_find);
	map[y][x] = 'F';
	i += fill(map[y][x], to_find, y + 1, x);
	i += fill(map[y][x], to_find, y - 1, x);
	i += fill(map[y][x], to_find, y, x - 1);
	i += fill(map[y][x], to_find, y, x + 1);
	return (i);
}