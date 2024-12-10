/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:34:32 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/10 18:09:47 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	j = 0;
	while (big[i] && i < len && little[j])
	{
		while (big[i + j] == little[j] && i + j < len)
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (0);
}

//Linea 26: Analiza si llegó al final de la cadena, indicador
//de que recorrió todo el string.

/* #include <stdio.h>
#include <string.h>

int main() {
    const char big[] = "Hello, world!";
    const char little[] = "world";
    char *result;

    result = ft_strnstr(big, little, 10);  // Busca en los primeros 10 caracteres
    if (result)
        printf("Subcadena encontrada: %s\n", result);
    else
        printf("Subcadena no encontrada.\n");

    return 0;
} */