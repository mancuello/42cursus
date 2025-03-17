/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:11:03 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/14 18:58:23 by mcuello          ###   ########.fr       */
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
		return (ft_error("Error: No se pudo inicializar la Minilibx.\n"));
	printf("MiniLibX inicializada correctamente.\n");	
	game->win = mlx_new_window(game->mlx, map->width * SPRITE_SIZE, map->height * SPRITE_SIZE, "so_long");
	if (!game->win)
		return (ft_error("Error: No se pudo crear la ventana.\n"));
	if (load_sprites(game) != 0)
		return (ft_error("Error: No se pueden cargar los sprites.\n"));
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	render_map(game);
	return (0);
}