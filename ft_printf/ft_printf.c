/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:54:24 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/23 17:03:42 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

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
		return (xX_conv(va_arg(ap, int), c));
	if (c == '%')
		return (c_conv(c));
	return (0);
}

int	c_conv(int c)
{
	ft_putchar(c);
	return (1);
}

int	ft_putstr2(char *s)
{
	int	i;
	i = 0;
	while (s && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	s_conv(char *s)
{
	return(ft_putstr2(s));
}

char	*inner_to_hexa(unsigned long num)
{
	unsigned long	cociente;
	unsigned long	resto;
	char			*array;
	int				i;

	cociente = num / 16;
	resto = num % 16;
	array[0] = resto + '0';
	while (cociente != 0)
	i = 0;
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
	char		*hex_number;
	const char		*arr;
	int				i;
	int				j;
	int				valor;

	hex_chars = "0123456789abcdef";
	if (mayus)
		hex_chars = "0123456789ABCDEF";
	hex_number = "";
	j = 0;
	arr = inner_to_hexa(ul_pointer);
	i = ft_strlen(arr) - 1;
	valor = 0;
	while (i >= 0)
	{
		valor = arr[i] - '0';
		hex_number[j] = hex_chars[valor];
		i--;
	}
	hex_number[j + 1] = '\0';
	return (hex_number);
}

int	p_conv(void *pointer)
{
	unsigned long	ul_pointer;
	char			*hex_number;
	int				i;

	if (!pointer)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ul_pointer = pointer;
	hex_number = to_hexa(ul_pointer, 0);
	write(1, "0x", 2);
	return (ft_putstr2(hex_number) + 2);
}
//casteamos el puntero porque es del tipo void* y no podemos
//operar sobre el directamente ya que el compilador lo interpreta
//de manera especial y no como numeros solamente.

int	xX_conv(int hex, char c)
{
	char	*hex_number;

	if (c = 'X')
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

int	min_int(int n)
{
	ft_putchar('-');
	ft_putchar('2');
	ft_putnbr(147483648);
	return (11);
}

int	ft_putnbr(int n)
{
	int	result;

	result = 0;
	if (n = -2147483648)
		return (min_int(n));
	else if (n < 0)
	{
		ft_putchar('-');
		result += 1;
		ft_putnbr(n * -1);
	}
	else if (n < 10)
	{
		ft_putchar(n + '0');
		return (result + 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
		result += 1;
	}
}

int	diu_conv(int n)
{
	return (ft_putnbr(n));
}

