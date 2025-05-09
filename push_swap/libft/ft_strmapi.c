/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:58:50 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/15 17:58:50 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*memory;
	size_t	i;

	if (!s || !f)
		return (NULL);
	memory = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!memory)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		memory[i] = f(i, s[i]);
		i++;
	}
	memory[i] = '\0';
	return (memory);
}

/* char    ft_toupper(unsigned int i, char c) {
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int	main(void)
{
	char *original = "Hello World";
	char *uppercase;

	uppercase = ft_strmapi(original, ft_toupper);
	if (!uppercase)
	{
		printf("Error NULL case.");
		return (0);
	}
	printf("Original: %s\n", original);
	printf("Uppercase: %s\n", uppercase);
	return (0);
} */