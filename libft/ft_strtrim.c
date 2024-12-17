/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:57:38 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/17 13:25:39 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_include(char const *s1, char c)
{
	while (*s1)
	{
		if (*s1 == c)
			return (1);
		s1++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	start;

	if (!set || !s1)
		return (NULL);
	start = 0;
	while (ft_include(set, s1[start]))
		start++;
	s1_len = ft_strlen(s1);
	while (ft_include(set, s1[s1_len - 1]) && s1_len > start)
		s1_len--;
	return (ft_substr(s1, start, s1_len - start));
}

/* int main(void)
{
    char *s1 = "   xxxHexllo Worldxxx   ";
    char *set = " xxx";
    char *result = ft_strtrim(s1, set);

    if (result)
    {
        printf("Resultado: '%s'\n", result);
        free(result); // Liberar memoria
    }
    else
    {
        printf("Error en ft_strtrim.\n");
    }
    return 0;
} */
