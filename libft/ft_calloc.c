/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:17:09 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/07 21:17:09 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t elem, size_t size)
{
	void	*reserv;

	reserv = malloc(elem * size);
	if (elem = 0 || size = 0 || !reserv)
		return (0);
	ft_bzero(reserv, elem * size);
	return (reserv);
}
