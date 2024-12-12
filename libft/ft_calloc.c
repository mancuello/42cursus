/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:17:09 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/12 18:48:33 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elem, size_t size)
{
	void	*reserv;

	reserv = malloc(elem * size);
	if (!reserv)
		return (NULL);
	ft_bzero(reserv, elem * size);
	return (reserv);
}
