/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:46:44 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/09 01:10:41 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_strcmp(char *first, char *second)
{
	while (*first && *second && *first == *second)
	{
		first++;
		second++;
	}
	return (*first - *second);
}
