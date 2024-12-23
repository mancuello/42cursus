/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:24:41 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/02 12:14:32 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

/* int main(void)
{
    printf("El caracter buscado esta aqui: %s", ft_strchr("hola mundo", '\0'));
    return (0);
} */

char	*santiago(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

char	*matute(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while ((str[i] != (char)c) && (str[i]))
		i++;
	if (str[i] || ((!((char)c) && !str[i])))
		return ((char *)(str + i));
	return ((char *)0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

int main(void)
{
    printf("El resultado mio es: %s\n", ft_strchr("teste", '\0'));
    printf("El resultado original es: %s\n", strchr("teste", '\0'));
    printf("El resultado santiago es: %s\n", santiago("teste", '\0'));
    printf("El resultado matute es: %s\n", matute("teste", '\0'));
    return (0);
}
