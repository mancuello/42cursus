/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:49:20 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/15 18:49:20 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		f(i, s);
		s++;
		i++;
	}
}

/* void	my_toupper(unsigned int i, char *c)
{
	if (*c >= 97 && *c <= 122)
		*c = *c - 32;
}

int	main(void)
{
	char	source[] = "hello world";
	
	printf("El original: %s\n", source);
	ft_striteri(source, my_toupper);
	printf("El modificado: %s", source);
	return (0);
} */