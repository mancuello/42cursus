/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:10:22 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/03/12 09:44:31 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *str)
{
	char	*c;
	int		i;
	int		len;

	len = ft_strlen(str);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
