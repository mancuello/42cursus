#include "cub3d.h"
//Esta implementacion solo lee hasta nulo o newline.
int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str && (str[i] != '\0' && str[i] != '\n'))
		i++;
	return (i);
}

static void render_images(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor,
		x * 32, y * 32);
	if (game->map->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			x * 32, y * 32);
	else if (game->map->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			x * 32, y * 32);
	else if (game->map->map[y][x] == 'P')
	{
		if (game->player_x == -1 && game->player_y == -1)
		{
			game->player_x = x;
			game->player_y = y;
		}
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			x * 32, y * 32);
	}
}

void render_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			render_images(game, x, y);
			x++;
		}
		y++;
	}
}

int	init_game(t_game *game, t_map *map)
{
	game->map = map;
	game->player_x = -1;
	game->player_y = -1;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_error("Error: No se pudo inicilizar la Minilibx.\n"));
	printf("Minilib inicializada correctamente.\n");
	printf("width: %d height: %d\n", map->width, map->height);
	game->win = mlx_new_window(game->mlx, RES_WIDTH,
			RES_HEIGHT, "cub3d");
	if (!game->win)
		return (ft_error("Error: no se pude crear la ventana.\n"));
	if (load_sprites(game) != 0)
		return (ft_error("Error: No se pueden cargar los sprites.\n"));
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	render_map(game);
	return (0);
}