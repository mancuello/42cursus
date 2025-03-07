/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:51:12 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/04 11:10:32 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
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
}	t_game;

int		read_map(char *filename, t_map *map);
void	free_map(t_map *map_data);
int	check_map_rules(t_map *map);
int	init_game(t_game *game, t_map *map);

#endif