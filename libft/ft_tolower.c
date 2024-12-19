/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:42:58 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/19 18:05:59 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/* int	main(void)
{
	int	number = 91;
	char	c = '[';
	int		result;
	int		result2;
	result = ft_tolower(number);
	result2 = tolower(number);
	printf("El resultado de: %i a ft_toLower es: %i\n", number, result);
	printf("El resultado de: %i a toLower es: %i\n", number, result2);
	
	result = ft_tolower(c),
	result2 = tolower(c);
	printf("El resultado de pasar un char: %c a ft_tolower es: %i\n", c, result);
	printf("El resultado de pasar un char: %c a tolower es: %i\n", c, result2);
	
	return(0);
} */
