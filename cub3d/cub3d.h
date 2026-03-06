#ifndef CUB3D_H
# define CUB3D_H

# define RES_WIDTH 640
# define RES_HEIGHT 400

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <mlx.h>
# include "libft/libft.h"
# include "key_codes.h"

	typedef struct s_map
	{
		char 	**map;
		int		width;
		int		height;
		int		player_count;
		int		exit_count;
	}	t_map;

	typedef struct s_fd
	{
		int 	height;
		int		elements;
		char	**line;
		char	*no_texture;
		char	*so_texture;
		char	*we_texture;
		char	*ea_texture;
		char	*floor_color;
		char	*ceiling_color;
		t_map	*map;
	}	t_fd;



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
	//int		read_map(char *filename, t_map *map_data);
	int		read_fd(char *filename, t_fd *fd_data);
	int		ft_error(char *str);
	int		load_sprites(t_game *game);
	void	move_player(t_game *game, int dx, int dy);
	int		ft_strlen2(char *str);
	int 	check_extension(char *str);

#endif