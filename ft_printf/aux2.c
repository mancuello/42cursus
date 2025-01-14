/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:54:59 by mcuello           #+#    #+#             */
/*   Updated: 2025/01/14 19:15:15 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*reverse(char *arr)
{
	char	temp;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(arr) - 1;
	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	return (arr);
}

char	*to_hexa(unsigned long num, int mayus)
{
	char		*hex_chars;
	char		*array;
	int			i;

	hex_chars = "0123456789abcdef";
	if (mayus)
		hex_chars = "0123456789ABCDEF";
	array = malloc(sizeof(char) * 17);
	if (!array)
		return (NULL);
	i = 0;
	while (num > 0)
	{
		array[i++] = hex_chars[num % 16];
		num = num / 16;
	}
	if (i == 0)
		array[i++] = '0';
	array[i] = '\0';
	return (reverse(array));
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
		hex_number = to_hexa((unsigned int)hex, 1);
	else
		hex_number = to_hexa((unsigned int)hex, 0);
	return (ft_putstr2(hex_number));
}
