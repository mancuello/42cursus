/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:34:32 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/23 13:25:46 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	j = 0;
	while (big[i] && i < len)
	{
		while ((little[j] != '\0') && (big[i + j] == little[j])
			&& (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

//Linea 26: Analiza si llegó al final de la cadena, indicador
//de que recorrió todo el string.

/* int main()
{
    const char big[] = "Hello, world!";
    const char little[] = "world";
    char *result;

    result = ft_strnstr(big, little, 12);
    if (result)
        printf("Subcadena encontrada: %s\n", result);
    else
        printf("Subcadena no encontrada.\n");

    return 0;
} */

/* int main(void)
{
    char *s = "A";
	size_t 	size = ft_strlen(s) + 1;
    
    printf("El resultado mio es: %s\n", ft_strnstr(s, s, size));
    printf("El resultado original es: %s\n", strnstr(s, s, size));
    return (0);
} */