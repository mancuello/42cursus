#include "cub3d.h"

int	load_sprites(t_game *game)
{
	int	width;
	int	height;

	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/green32.xpm",
			&width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/character.xpm",
			&width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	if (!game->player || !game->exit
		|| !game->wall || !game->floor)
		return (1);
	return (0);
}