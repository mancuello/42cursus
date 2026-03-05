#include "cub3d.h"

char **clean_line(char *line)
{
	char	*tmp;
	char	**arr;
	int		i;

	i = 0;
	tmp = ft_strtrim(line, " ");
	arr = ft_split(tmp, ' ');
	free(tmp);
	while (arr[i])
		i++;
	if (i != 2)
		return (NULL);
	return(arr);
}

static void	get_rgb(char *line, t_fd *fd_data)
{
	char	**arr;

	arr = clean_line(line);
	if (!arr)
		return ;
	//assign here
	free(arr[0]);
	free(arr[1]);
}

static void assign_path(char **arr, t_fd *fd_data)
{
	if ((arr[0][0] == 'N' && arr[0][1] == 'O' && ft_strlen(arr[0]) == 2) || (arr[0][0] == 'N' && ft_strlen(arr[0]) == 1))
	{
		fd_data->no_texture = arr[1];
		fd_data->elements++;
	}
	if ((arr[0][0] == 'S' && arr[0][1] == 'O' && ft_strlen(arr[0]) == 2) || (arr[0][0] == 'S' && ft_strlen(arr[0]) == 1))
	{
		fd_data->no_texture = arr[1];
		fd_data->elements++;
	}
	if ((arr[0][0] == 'W' && arr[0][1] == 'E' && ft_strlen(arr[0]) == 2) || (arr[0][0] == 'W' && ft_strlen(arr[0]) == 1))
	{
		fd_data->no_texture = arr[1];
		fd_data->elements++;
	}
	if ((arr[0][0] == 'E' && arr[0][1] == 'A' && ft_strlen(arr[0]) == 2) || (arr[0][0] == 'A' && ft_strlen(arr[0]) == 1))
	{
		fd_data->no_texture = arr[1];
		fd_data->elements++;
	}

}

static void	get_path(char *line, t_fd *fd_data)
{
	char	**arr;

	arr = clean_line(line);
	if (!arr)
		return ;
	assign_path(arr, fd_data);
	free(arr[0]);
	free(arr[1]);
}

static void init_elements(t_fd *fd_data)
{
	fd_data->no_texture = NULL;
	fd_data->so_texture = NULL;
	fd_data->we_texture = NULL;
	fd_data->ea_texture = NULL;
	fd_data->floor_color = NULL;
	fd_data->ceiling_color = NULL;
	fd_data->elements = 0;
}

static int	get_elements(t_fd *fd_data)
{
	int	i;
	int flag;

	i = 0;
	init_elements(fd_data);
	while (fd_data->line[i])
	{
		if (fd_data->line[i][0] == 'N' || fd_data->line[i][0] == 'S'
			|| fd_data->line[i][0] == 'W' || fd_data->line[i][0] == 'E')
			get_path(fd_data->line[i], fd_data);
		else if (fd_data->line[i][0] == 'F' || fd_data->line[i][0] == 'C')
			get_rgb(fd_data->line[i], fd_data);
		else if (fd_data->line[i][0] == '\n')
			i++;
		else
			return (ft_error("Error: invalid structure <mapa.cub>\n"), -1);
		i++;
	}
	if (!fd_data->line[i] || fd_data->elements != 6)
		return (ft_error("Error: invalid structure <mapa.cub>\n"), -1);
	if (get_map(fd_data, i) == -1)
		return (-1);
	return (0);
}

static int	parse_fd(int fd, t_fd *fd_data)
{
	int i;
	
	i = 0;
	while (i < fd_data->height)
	{
		fd_data->line[i] = get_next_line(fd);
		if (!fd_data->line[i])
			return (ft_error("Error: fallo en el parseo del fd.\n"), -1);
		i++;
	}
	fd_data->line[i] = NULL;
	close(fd);
	if (get_elements(fd_data) == -1)
		return (-1);
	return (0);
}

static int	count_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	read_fd(char *filename, t_fd *fd_data)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_error("Error: Fallo al leer el descriptor de archivo.\n"), -1);
	fd_data->height = count_lines(fd);
	if (fd_data->height == 0)
		return (ft_error("Error: Fallo al leer el descriptor de archivo.\n"), -1);
	fd = open(filename, O_RDONLY);
	fd_data->line = malloc(sizeof(char *) * (fd_data->height + 1));
	if (!fd_data->line)
		return (ft_error("Error: Fallo al leer el descriptor de archivo.\n"), -1);
	parse_fd(fd, fd_data);
	if (validations(fd_data) == -1)
		return (-1);
	ft_printf("Mapa leído correctamente.\n");
	return (0);
}
