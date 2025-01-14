/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:45:39 by mcuello           #+#    #+#             */
/*   Updated: 2025/01/13 19:52:58 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	min_int(void)
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
	if (n == -2147483648)
		return (min_int());
	else if (n < 0)
	{
		ft_putchar('-');
		result += 1;
		ft_putnbr(n * -1);
	}
	else if (n < 10)
	{
		ft_putchar(n + '0');
		result += 1;
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
		result += 1;
	}
	return (result);
}

int	diu_conv(int n)
{
	printf("\nRetorno dentro: %i\n", ft_putnbr(n));
	return (ft_putnbr(n));
}
