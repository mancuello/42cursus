/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:36:51 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/14 19:07:03 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_sprites(t_game *game)
{
	int	width;
	int	height;

	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/green32.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/character.xpm", &width, &height);
	game->collect = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &width, &height);
	if (!game->player || !game->collect || !game->exit || !game->wall || !game->floor)
		return (1);
	return (0);
}