/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:50:48 by mcuello           #+#    #+#             */
/*   Updated: 2025/02/01 16:46:42 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void		ft_putchar(char c);
int			ft_printf(char const *s, ...);
int			conversions(char c, va_list ap);
int			c_conv(int c);
int			s_conv(char *s);
int			di_conv(int n);
int			u_conv(int n);
int			p_conv(void *pointer);
int			x_conv(int hex, char c);
int			min_int(void);
int			ft_putnbr(unsigned int n);
int			ft_putstr2(char *s);
char		*to_hexa(unsigned long ul_pointer, int mayus);
char		*reverse(char *arr);
size_t		ft_strlen(const char *c);

#endif