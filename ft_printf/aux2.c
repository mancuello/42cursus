/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:54:59 by mcuello           #+#    #+#             */
/*   Updated: 2025/01/10 18:30:46 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*inner_to_hexa(unsigned long num)
{
	unsigned long	cociente;
	unsigned long	resto;
	char			*array;
	int				i;

	cociente = num / 16;
	resto = num % 16;
	array = malloc(sizeof(char) * 17);
		if (!array)
    		return (NULL);
	array[0] = resto + '0';
	i = 0;
	while (cociente != 0)
	{
		cociente = cociente / 16;
		resto = cociente % 16;
		array[++i] = resto + '0';
	}
	array[i] = '\0';
	return (array);
}

char	*to_hexa(unsigned long ul_pointer, int mayus)
{
	const char		*hex_chars;
	char			*hex_number;
	const char		*arr;
	int				i;
	int				j;
	int				valor;

	hex_chars = "0123456789abcdef";
	if (mayus)
		hex_chars = "0123456789ABCDEF";
	arr = inner_to_hexa(ul_pointer);
	if (!arr)
		return (NULL);
	hex_number = malloc(ft_strlen(arr) + 1);
	if (!hex_number)
	{
		free(arr);
		return (NULL);
	}
	j = 0;
	i = ft_strlen(arr) - 1;
	valor = 0;
	while (i >= 0)
	{
		valor = arr[i] - '0';
		hex_number[j++] = hex_chars[valor];
		i--;
	}
	hex_number[j + 1] = '\0';
	free(arr);
	return (hex_number);
}

int	p_conv(void *pointer)
{
	unsigned long	ul_pointer;
	char			*hex_number;

	if (!pointer)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ul_pointer = (unsigned long)pointer;
	hex_number = to_hexa(ul_pointer, 0);
	write(1, "0x", 2);
	return (ft_putstr2(hex_number) + 2);
}
//casteamos el puntero porque es del tipo void* y no podemos
//operar sobre el directamente ya que el compilador lo interpreta
//de manera especial y no como numeros solamente.

int	x_conv(int hex, char c)
{
	char	*hex_number;

	if (c == 'X')
		hex_number = to_hexa((unsigned long)hex, 1);
	hex_number = to_hexa((unsigned long)hex, 0);
	return (ft_putstr2(hex_number));
}

/* int	X_conv(int hex)
{
	char	*hex_number;

	hex_number = to_hexa((unsigned long)hex, 1);
	return (ft_putstr2(hex_number));
} */