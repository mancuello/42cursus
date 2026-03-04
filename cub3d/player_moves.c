#include "cub3d.h"

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
		exit_game(game);
		return ;
	}
	//game->moves++;
	//printf("Movimientos: %d\n", game->moves);
/* 	if (game->map->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map->map[new_y][new_x] = '0';
	} */
	game->map->map[game->player_y][game->player_x] = '0';
	game->map->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	render_map(game);
}