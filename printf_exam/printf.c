/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:15:46 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/25 17:42:02 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	s_conversion(char *s)
{
	int	i;

	if (!s)
		return (s_conversion("(null)"));
	i = 0;
	while (s && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	result;

	result = 0;
	if (n < 10)
	{
		ft_putchar(n + '0');
		result ++;
	}
	else
	{
		result += ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
		result += 1;
	}
	return (result);
}

int	d_conversion(int d)
{
	int	result;

	result = 0;
	if (d == -2147483648)
		return (min_int());
	else if (d < 0)
	{
		ft_putchar('-');
		result += 1;
		result += ft_putnbr(d * -1);
	}
	else
	{
		result += ft_putnbr(d);
	}
	return (result);
}

char	*to_hexa(unsigned long num)
{
	char	*hex_chars;

	hex_chars = "0123456789abcdef";
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

int	x_conversion(int n)
{
	char	*hex_number;

	hex_number = to_hexa((unsigned int)n);
	return (ft_putstr2(hex_number));
}

int	conversions(char c, va_list ap)
{
	if (c == 's')
		return (s_conversion(va_arg(ap, char *)));
	if (c == 'd')
		return (d_conversion(va_arg(ap, int)));
	if (c == 'x')
		return (x_conversion(va_arg(ap, int)));
}

int	ft_printf(const char *s, ...)
{
	int	result;
	int	i;
	va_list	ap;

	result = 0;
	i = 0;
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
			putchar(s[i]);
			result++;
		}
		i++;
	}
	va_end(ap);
	return (result);
}
