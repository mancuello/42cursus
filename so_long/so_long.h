/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:51:12 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/11 17:41:44 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# define SPRITE_SIZE 32

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "mlx_keycodes.h"
//# include "libft.h"

typedef struct s_map {
	char	**map;
	int		width;
	int		height;
	int		player_count;
	int		collect_count;
	int		exit_count;
}	t_map;

typedef struct s_game {
	void	*mlx;
	void	*win;
	t_map	*map;
	void	*player;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*floor;
	int		player_x;
	int		player_y;
	int		collected;
	int		moves;
}	t_game;

int		read_map(char *filename, t_map *map);
void	free_map(t_map *map_data);
int		check_map_rules(t_map *map);
int		init_game(t_game *game, t_map *map);
void 	render_map(t_game *game);
int		load_sprites(t_game *game);
int		exit_game(t_game *game);
int		key_hook(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);




#endif