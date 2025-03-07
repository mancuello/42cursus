#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	fd = open("maps/map_valid.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("Error abriendo el archivo");
		return (1);
	}

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
