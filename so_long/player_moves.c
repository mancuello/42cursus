/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:28:15 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/18 16:09:47 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_door(t_game *game)
{
	if (game->collected == game->map->collect_count)
	{
		game->moves++;
		printf("Movimientos: %d\n", game->moves);
		printf("Has ganado!\n");
		exit_game(game);
	}
	else
	{
		printf("Necesitas recoger todos los colecionables primero.\n");
		return ;
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map->map[new_y][new_x] == '1')
		return ;
	if (game->map->map[new_y][new_x] == 'E')
	{
		exit_door(game);
		return ;
	}
	game->moves++;
	printf("Movimientos: %d\n", game->moves);
	if (game->map->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map->map[new_y][new_x] = '0';
	}
	game->map->map[game->player_y][game->player_x] = '0';
	game->map->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	render_map(game);
}
