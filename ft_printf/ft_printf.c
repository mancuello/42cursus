/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:54:24 by mcuello           #+#    #+#             */
/*   Updated: 2025/01/13 01:08:55 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf(char const *s, ...)
{
	int			i;
	int			result;
	va_list		ap;

	i = 0;
	result = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			result += conversions(s[i], ap);
		}
		else
		{
			ft_putchar(s[i]);
			result++;
		}
		i++;
	}
	va_end(ap);
	return (result);
}

//La funcion devuelve un entero que indica el numero de caracteres
//que se han impreso en la pantalla.

int	conversions(char c, va_list ap)
{
	if (c == 'c')
		return (c_conv(va_arg(ap, int)));
	if (c == 's')
		return (s_conv(va_arg(ap, char *)));
	if (c == 'p')
		return (p_conv(va_arg(ap, void *)));
	if (c == 'd' || c == 'i' || c == 'u')
		return (diu_conv(va_arg(ap, int)));
	if (c == 'x' || c == 'X')
		return (x_conv(va_arg(ap, int), c));
	if (c == '%')
		return (c_conv(c));
	return (0);
}

int	main(void)
{
    char    caracter = 'a';
    char    *string = "hola mundo";
    int     number = 1;


    //Prueba solo de caracteres.
	ft_printf("Custom print\n");
	printf("Original Print\n");

    //Prueba con especificador %c
    ft_printf("Custom  => char: %c\n", caracter);
    printf("Original=> char: %c\n", caracter);

    //Prueba con especificador %s
    ft_printf("Custom  => char: %s\n", string);
    printf("Original=> char: %s\n", string);

    //Prueba con especificador %p
    ft_printf("Custom  => char: %p\n", string);
    printf("Original=> char: %p\n", string);

    //Prueba con especificador %d
    ft_printf("Custom  => char: %d\n", number);
    printf("Original=> char: %d\n", number);

    //Prueba con especificador %i
    ft_printf("Custom  => char: %i\n", number);
    printf("Original=> char: %i\n", number);

    //Prueba con especificador %u
    ft_printf("Custom  => char: %u\n", number);
    printf("Original=> char: %u\n", number);

    //Prueba con especificador %x
    ft_printf("Custom  => char: %x\n", caracter);
    printf("Original=> char: %x\n", caracter);

    //Prueba con especificador %X
    ft_printf("Custom  => char: %X\n", caracter);
    printf("Original=> char: %X\n", caracter);

    //Prueba con especificador %%
    ft_printf("Custom  => char: %%\n");
    printf("Original=> char: %%\n");

	return (0);
}
