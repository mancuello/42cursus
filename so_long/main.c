/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:59:05 by mcuello           #+#    #+#             */
/*   Updated: 2025/03/07 18:47:20 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
	{
		printf("Uso: %s <mapa.ber>/n", argv[0]);
		return (1);
	}
	if (read_map(argv[1], &map) == -1)
	{
		printf("Error: No se pudo leer el mapa.\n");
		return (1);
	}
	printf("verificando reglas del mapa....\n");
	if (check_map_rules(&map) == -1)
	{
		printf("Error: Mapa inválido.\n");
		free_map(&map);
		return (1);
	}
	printf("Iniciando el juego...\n");
	if (init_game(&game, &map) == 1)
	{
		free_map(&map);
		return (1);
	}
	printf("Entrando en mlx loop.\n");
	mlx_loop(game.mlx);
	free_map(&map);
	return (0);
}