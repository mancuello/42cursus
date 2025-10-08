#include <unistd.h>
#include <string.h>
#include <stdio.h>

static void	print_recursive(int j)
{
	int	i;

	i = 0;
	while (i - j)
	{
		printf("*");
		i++;
	}
}

static void	replace(char *buffer, char *replace)
{
	int	i;
	int	j;
	int	base;

	j = 0;
	i = 0;
	base = 0;
	while (buffer[base])
	{
		while (buffer[i] == replace[j])
		{
			i++;
			j++;
		}
		if (j == (int)strlen(replace))
		{
			print_recursive(j);
			base = base + j;
		}
		else
		{
			printf("%c", buffer[base]);
			base++;
		}
		i = base;
		j = 0;
	}
}
//MANEJAR OWVERFLOW

static void	filter(char *str)
{
	char 	buffer[10];
	int		n_bites;

	n_bites = read(0, buffer, 10);
	buffer[n_bites] = '\0';
	replace(buffer, str);
	return ;
}


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		return (1);
	}
	else
	{
		filter(argv[1]);
	}
	return (0);
}
