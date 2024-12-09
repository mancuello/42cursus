/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:06:56 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/09 16:39:43 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	src_len;
	char	*sub;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
		return (ft_strdup(""));
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	if (len > src_len - start)
		len = src_len - start;
	i = 0;
	while(i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}


/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

int main(void)
{
    char *original = "Hello, 42 Students!";
    char *substring;

    // Caso 1: Extraer una parte del medio
    substring = ft_substr(original, 17, 20);
    if (substring)
    {
        printf("Caso 1 - Resultado esperado: \"nts!\"\n");
        printf("Caso 1 - Resultado obtenido: \"%s\"\n", substring);
        free(substring);
    }

    // Caso 2: Extraer desde el inicio
    substring = ft_substr(original, 0, 5);
    if (substring)
    {
        printf("\nCaso 2 - Resultado esperado: \"Hello\"\n");
        printf("Caso 2 - Resultado obtenido: \"%s\"\n", substring);
        free(substring);
    }

    // Caso 3: Extraer más allá de la longitud del string
    substring = ft_substr(original, 15, 10);
    if (substring)
    {
        printf("\nCaso 3 - Resultado esperado: \"nts!\"\n");
        printf("Caso 3 - Resultado obtenido: \"%s\"\n", substring);
        free(substring);
    }

    // Caso 4: Empezar después de la longitud de la cadena original
    substring = ft_substr(original, 25, 5);
    if (substring)
    {
        printf("\nCaso 4 - Resultado esperado: \"\"\n");
        printf("Caso 4 - Resultado obtenido: \"%s\"\n", substring);
        free(substring);
    }
	else 
		printf("no entro al caso 4\n");
    return 0;
} */
