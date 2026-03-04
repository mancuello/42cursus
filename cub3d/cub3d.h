#ifndef CUB3D_H
# define CUB3D_H

# define TILE_SIZE 32

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "key_codes.h"

typedef struct s_map
{
	char **map;
	int		width;
	int		height;
	int		player_count;
	int		exit_count;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	void	*player;
	void	*wall;
	void	*exit;
	void	*floor;
	int		player_x;
	int		player_y;
}	t_game;

typedef struct s_pos
{
	int y;
	int x;
}	t_pos;

void	render_map(t_game *game);
void	free_map(t_map *map);
int		init_game(t_game *game, t_map *map);
int		key_hook(int keycode, t_game *game);
int		exit_game(t_game *game);
int		read_map(char *filename, t_map *map_data);
int		ft_error(char *str);
int		load_sprites(t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		ft_strlen2(char *str);

#endif