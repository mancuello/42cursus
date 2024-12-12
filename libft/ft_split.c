/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:08:24 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/12 18:25:33 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(void **ss)
{
	size_t	i;

	i = 0;
	while (ss[i])
	{
		free(ss[i]);
		i++;
	}
	free(ss);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	amountof_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (s[0] != c && (s[1] == c || s[1] == 0))
			i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	start;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (amountof_words(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	start = 0;
	while (i < amountof_words(s, c))
	{
		while (s[start] == c)
			start++;
		array[i] = ft_substr(s, start, word_len(s + start, c));
		if (!array[i])
			return (ft_free((void **)array), NULL);
		i++;
		start += word_len(s + start, c);
	}
	array[i] = NULL;
	return (array);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *str1 = "Hola mundo 42!";
    char delim1 = ' ';
    char *str2 = "42,,,es,,la,,mejor,,,escuela";
    char delim2 = ',';
    char *str3 = "";
    char delim3 = ',';

    // Prueba 1
    printf("=== Prueba 1 ===\n");
    char **result1 = ft_split(str1, delim1);
    if (result1) {
        for (int i = 0; result1[i]; i++) {
            printf("Subcadena [%d]: \"%s\"\n", i, result1[i]);
            free(result1[i]); // Liberar memoria de cada subcadena
        }
        free(result1); // Liberar el array de punteros
    }

    // Prueba 2
    printf("\n=== Prueba 2 ===\n");
    char **result2 = ft_split(str2, delim2);
    if (result2) {
        for (int i = 0; result2[i]; i++) {
            printf("Subcadena [%d]: \"%s\"\n", i, result2[i]);
            free(result2[i]); // Liberar memoria de cada subcadena
        }
        free(result2); // Liberar el array de punteros
    }

    // Prueba 3
    printf("\n=== Prueba 3 ===\n");
    char **result3 = ft_split(str3, delim3);
    if (result3) {
        for (int i = 0; result3[i]; i++) {
            printf("Subcadena [%d]: \"%s\"\n", i, result3[i]);
            free(result3[i]); // Liberar memoria de cada subcadena
        }
        free(result3); // Liberar el array de punteros
    }

    return 0;
} */