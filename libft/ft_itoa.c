/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:27:28 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/12 19:27:11 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static	int	characters(int n)
{
	if (n < 0)
		return (digits(n * -1) + 1);
	return (digits(n));
}

static	int	ft_module(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char			*dest;
	unsigned int	module;
	unsigned int	i;

	if (n == INT_MIN)
		return (strdup("-2147483648"));
	i = characters(n);
	module = ft_module(n);
	dest = ft_calloc(i + 1, sizeof(char));
	dest[i] = '\0';
	while (i > 0)
	{
		dest[--i] = module % 10 + '0';
		module = module / 10;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}

/* int	main(void)
{
	int	numero = -54;
	int	numero2 = 354;
	int numero3 = 0;
	char	*resultado;

	resultado = ft_itoa(numero);
	printf("El numero pasado es: %d y el 
		resultado obtenido: %s\n" numero, resultado);
	free(resultado);
	
	resultado = ft_itoa(numero2);
	printf("El numero pasado es: %d y el 
		resultado obtenido: %s\n" numero2, resultado);
	free(resultado);

	resultado = ft_itoa(numero3);
	printf("El numero pasado es: %d y el 
		resultado obtenido: %s\n" numero3, resultado);
	free(resultado);

	return (0);
} */