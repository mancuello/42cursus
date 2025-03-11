/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:11:03 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/11 16:24:54 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	init_game(t_game *game, t_map *map)
{
	game->map = map;
	game->player_x = -1;
	game->player_y = -1;
	game->collected = 0;
	game->moves = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		printf("Error: No se pudo inicializar MiniLibX.\n");
		return (1);
	}
	printf("MiniLibX inicializada correctamente.\n");	
	game->win = mlx_new_window(game->mlx, map->width * 64, map->height * 64, "so_long");
	if (!game->win)
	{
		printf("Error; No se pudo crear la ventana.\n");
		free(game->mlx);
		return (1);
	}
	if (load_sprites(game) != 0)
		return (1);
	mlx_key_hook(game->win, key_hook(), game);
	mlx_hook(game->win, 17, 0, exit_game(), game);
	render_map(game);
	return (0);
}