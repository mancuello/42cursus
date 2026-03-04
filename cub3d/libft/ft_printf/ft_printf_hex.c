/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:00:41 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/03/12 09:46:01 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_pointer(void *ptr)
{
	unsigned long long	addr;
	char				*hex_base;
	char				buffer[17];
	int					len;
	int					total_len;

	hex_base = "0123456789abcdef";
	addr = (unsigned long long)ptr;
	if (addr == 0)
		return (write(1, "(nil)", 5));
	len = 0;
	while (addr)
	{
		buffer[len++] = hex_base[addr % 16];
		addr /= 16;
	}
	total_len = write(1, "0x", 2);
	while (len--)
		total_len += write(1, &buffer[len], 1);
	return (total_len);
}

int	get_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*ft_utoa_hex(unsigned int num, char format)
{
	char	*hex_base;
	char	*str;
	int		len;

	if (format == 'x')
		hex_base = "0123456789abcdef";
	else
		hex_base = "0123456789ABCDEF";
	len = get_hex_len(num);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = hex_base[num % 16];
		num /= 16;
	}
	return (str);
}

int	ft_print_hex(unsigned int num, char format)
{
	char	*hex_str;
	int		len;

	hex_str = ft_utoa_hex(num, format);
	if (!hex_str)
		return (0);
	len = ft_putstr(hex_str);
	free(hex_str);
	return (len);
}
