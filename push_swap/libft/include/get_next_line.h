/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:58:52 by mcuello           #+#    #+#             */
/*   Updated: 2025/05/13 00:10:14 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include "libft.h"

void	*ft_calloc(size_t items, size_t size);
void	ft_copy(char *src, char *dest);
char	*ft_concat(char **first, char *second);
int		get_buffer(int fd, char *buffer, int *i);
char	*process_buffer(int fd, char *temp);
char	*get_next_line(int fd);

#endif