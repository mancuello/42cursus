/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:07:11 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/14 15:17:06 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_map(t_game *game)
{
	int x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->floor, x * SPRITE_SIZE, y * SPRITE_SIZE);
			if (game->map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
			else if (game->map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect, x * SPRITE_SIZE, y * SPRITE_SIZE);
			else if (game->map->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, x * SPRITE_SIZE, y * SPRITE_SIZE);
			else if (game->map->map[y][x] == 'P')
			{
				if (game->player_x == -1 && game->player_y == -1)
				{
					game->player_x = x;
					game->player_y = y;
				}
				mlx_put_image_to_window(game->mlx, game->win, game->player, x * SPRITE_SIZE, y * SPRITE_SIZE);
			}
			x++;
		}
		y++;
	}
}
