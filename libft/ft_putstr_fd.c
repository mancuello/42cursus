/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:39:05 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/15 21:39:05 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

/* int	main(void)
{
	char	*b = "HELLO-WORLD";

	ft_putstr_fd(b, 1);
	return (0);
} */