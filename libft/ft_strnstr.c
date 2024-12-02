/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:34:32 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/02 17:55:48 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;

	count = 0;
	if (!*str2)
		return ((char *)str1);
	i = 0;
	j = 0;
	while (i < len && str1[i] && str2[j])
	{
		if (str1[i] == str2[j])
		{
			i++;
			j++;
			count++;
			if (count == ft_strlen(str2))
			{
				i -= count;
				return ((char *)str1 + i);
			}
		}
		else
		{
			i++;
			count = 0;
		}
	}
	return (NULL);
}

// int main() {
// 	const char *haystack = "hola esto es un mensaje"; // Cadena vacC-a
// 	const char *needle1 = "esto";  // Cadena vacC-a
// 	//const char *needle2 = "esun"; // Cadena no vacC-a

// 	// Caso 1: needle tambiC)n estC! vacC-o
// 	const char *result1 = strnstr(haystack, needle1, 8);
// 	printf("needle1 deberia encontrar: '%s'\n", result1);

// 	// Caso 2: needle no estC! vacC-o
// 	//char *result2 = strnstr(haystack, needle2, 16);
// 	//printf("needle2 no deberia salir: '%s'\n", result2);
// 	return 0;
// }