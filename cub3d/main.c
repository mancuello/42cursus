#include "cub3d.h"

int	ft_error(char *str)
{
	printf("%s", str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
	{
		printf("Uso: %s <mapa.cub>\n", argv[0]);
		return (1);
	}
	if (check_extension(argv[1]) == -1)
		return (ft_error("Error: El archivo debe tener la extension .cub\n"));
	if (read_map(argv[1], &map) == -1)
		return (ft_error("Error: No se pudo leer el mapa.\n"));
	printf("verificando reglas del mapa....\n");
/* 	if (check_map_rules(&map) == -1)
	{
		free_map(&map);
		return (ft_error("Error: Mapa inválido.\n"));
	} */
	printf("Iniciando el juego...\n");
	if (init_game(&game, &map) == 1)
		return (1);
	mlx_loop(game.mlx);
	exit_game(&game);
	return (0);
}