/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:58:52 by mcuello           #+#    #+#             */
/*   Updated: 2025/01/27 18:21:40 by mcuello          ###   ########.fr       */
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

size_t	ft_strlen(const char *c);
int		get_newline_char(char *buffer);
void	*ft_calloc(size_t items, size_t size);
char	*ft_concat(char *first, char *second, int start_second);
void	ft_bzero(char *buffer, size_t size);
char	*get_next_line(int fd);


#endif