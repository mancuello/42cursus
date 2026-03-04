/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:58:34 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/03/12 09:46:10 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* int	ft_printnum(int n)
{
	int		i;
	char	*num;

	num = ft_itoa(n);
	if (!num)
		return (0);
	i = 0;
	while (num[i])
		i += write(1, &num[i], 1);
	free(num);
	return (i);
} */

char	*ft_utoa(unsigned int n)
{
	int				len;
	unsigned int	temp;
	char			*str;

	if (n == 0)
		return (ft_strdup("0"));
	len = 0;
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return ((void *)0);
	str[len] = '\0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_utoa(n);
	len = 0;
	if (!str)
		return (0);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	conversion(const char format, va_list args)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (format == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		i += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'p')
		i += ft_print_pointer(va_arg(args, void *));
	else if (format == 'x' || format == 'X')
		i += ft_print_hex(va_arg(args, unsigned int), format);
	else
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_chars;

	va_start(args, format);
	i = 0;
	total_chars = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			total_chars += conversion(format[i + 1], args);
			i++;
		}
		else
			total_chars += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (total_chars);
}
