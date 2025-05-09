/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:13:54 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/16 16:39:44 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	char	*cpy;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	cpy = dest;
	while (*s1)
		*dest++ = *s1++;
	while (*s2)
		*dest++ = *s2++;
	*dest = '\0';
	return (cpy);
}

/* int	main(void)
{
	char	*s1 = "Hola, ";
	char	*s2 = "mundo!";
	char	*result;

	result = ft_strjoin(s1, s2);
	if (result)
	{
		printf("Resultado de ft_strjoin: %s\n", result);
		free(result);
	}
	else
		printf("Error al unir las cadenas.\n");

	return (0);
} */