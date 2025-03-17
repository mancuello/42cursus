/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:04:46 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/17 17:13:32 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_map(game->map);
	exit(0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}
