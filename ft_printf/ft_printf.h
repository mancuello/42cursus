/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:50:48 by mcuello           #+#    #+#             */
/*   Updated: 2025/01/10 18:27:34 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

void		ft_putchar(char c);
int			ft_printf(char const *s, ...);
int			conversions(char c, va_list ap);
int			c_conv(int c);
int			s_conv(char *s);
int			diu_conv(int n);
int			p_conv(void *pointer);
int			x_conv(int hex, char c);
int			min_int(int n);
int			ft_putnbr(int n);
int			ft_putstr2(char *s);
char		*inner_to_hexa(unsigned long num);
char		*to_hexa(unsigned long ul_pointer, int mayus);

#endif