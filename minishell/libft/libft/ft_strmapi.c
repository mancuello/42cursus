/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:53:10 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/03/12 09:44:53 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*c;

	len = ft_strlen(s);
	c = (char *)malloc((len + 1) * sizeof(char *));
	if (!c)
		return (NULL);
	i = 0;
	while (i < len)
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = 0;
	return (c);
}
