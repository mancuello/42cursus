/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:32:48 by marvin            #+#    #+#             */
/*   Updated: 2025/03/12 09:44:15 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	char	*p;
	size_t	i;

	p = (char *)ptr;
	i = 0;
	while (i < num)
	{
		p[i] = value;
		i++;
	}
	return (ptr);
}
