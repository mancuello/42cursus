/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:11:03 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/07 18:48:29 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	init_game(t_game *game, t_map *map)
{
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
	game->map = map;
	return (0);
}