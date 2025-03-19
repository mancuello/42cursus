/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:59:05 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/19 18:43:38 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_extension(const char *filename)
{
	int	len;

	len = 0;
	while (filename[len])
		len++;
	if (len < 4)
		return (-1);
	if (filename[len - 4] == '.'
		&& filename[len - 3] == 'b'
		&& filename[len - 2] == 'e'
		&& filename[len - 1] == 'r')
		return (0);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
	{
		printf("Uso: %s <mapa.ber>\n", argv[0]);
		return (1);
	}
	if (check_extension(argv[1]) == -1)
		return (ft_error("Error: El archivo debe tener la extension .ber\n"));
	if (read_map(argv[1], &map) == -1)
		return (ft_error("Error: No se pudo leer el mapa.\n"));
	printf("verificando reglas del mapa....\n");
	if (check_map_rules(&map) == -1)
		return (ft_error("Error: Mapa inválido.\n"));
	printf("Iniciando el juego...\n");
	if (init_game(&game, &map) == 1)
		return (1);
	mlx_loop(game.mlx);
	exit_game(&game);
	return (0);
}
