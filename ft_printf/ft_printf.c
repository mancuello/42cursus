/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:54:24 by mcuello           #+#    #+#             */
/*   Updated: 2025/01/10 18:33:26 by mcuello          ###   ########.fr       */
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
	ft_printf("mi primer resultado");
	printf("resultado original");
	return (0);
}
