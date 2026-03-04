#include "cub3d.h"


int check_extension(char *str)
{
	char *extension;
	size_t i;
	size_t j;

	extension = ft_strdup(".cub");
	if (str[0] == '\0')
		return (-1);
	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i + j] && (str[i + j] == extension[j]))
			j++;
		if (j == 4 && str[i + j] == '\0')
		{
			if (j == ft_strlen(str))
				return (-1);
			return (0);
		}
		i++;
	}
	return (-1);
}
