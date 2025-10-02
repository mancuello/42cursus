/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:22:43 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/04/02 09:33:59 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen_gnl_bonus(const char *c)
{
	size_t	i;

	if (!c)
		return (0);
	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl_bonus(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*joined;
	size_t	i;
	size_t	j;

	len1 = ft_strlen_gnl_bonus(s1);
	len2 = ft_strlen_gnl_bonus(s2);
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len1)
		joined[i++] = s1[j++];
	j = 0;
	while (j < len2)
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

int	gnl_has_newline_bonus(const char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}
