/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:39:12 by mcuello           #+#    #+#             */
/*   Updated: 2024/12/18 16:53:03 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
//# include	<string.h>
//# include	<stdio.h>

//Characters comprobation
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

//Memory manipulation
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *str, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_calloc(size_t elem, size_t size);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_bzero(void *src, size_t n);

//String manipulation
size_t		ft_strlen(const char *c);
int			ft_strncmp(char *str1, char *str2, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

//Conversion
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);

//Console
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
#endif