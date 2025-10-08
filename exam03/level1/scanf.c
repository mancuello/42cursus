/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:52:09 by mcuello           #+#    #+#             */
/*   Updated: 2025/07/29 17:28:02 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
	char	c;

	c = fgetc(f);
	while(c == ' ' || c == '\n' || c == '\t')
	{
		c = fgetc(f);
	}
	if (c == EOF)
		return -1;
	else
		ungetc(c, f);
    return (1);
}

int match_char(FILE *f, char c)
{
	char	x;

	x = fgetc(f);
	if (x == c)
		return 1;
	else if (x == EOF)
		return -1;
	else
		ungetc(x, f);
	return 0;
}

int scan_char(FILE *f, va_list ap)
{
	char 	*dest;
	char	c;

	c = fgetc(f);
	if (c == EOF)
		return -1;
	dest = va_arg(ap, char *);
	*dest = (char)c;
	
    return (1);
}

int scan_int(FILE *f, va_list ap)
{
	int		*dest;
	char	c;

	dest = va_arg(ap, int *);
	c = fgetc(f);
	if (c == EOF)
		return -1;
	while (c != EOF)
	{
		if (isdigit(c))
		{
			*dest = *dest * 10 + ((char)c - 48);
			c = fgetc(f);
		}
		else
			break;
	}
    return (1);
}

int scan_string(FILE *f, va_list ap)
{
	char	*dest;
	char	c;

	dest = va_arg(ap, char *);
	c = fgetc(f);
	if (c == EOF)
		return -1;
	while (c != EOF && !isspace(c))
	{
		*dest = (char)c;
		dest++;
		c = fgetc(f);
	}
	*dest = '\0';
    return (1);
}

int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) == -1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}

int ft_scanf(const char *format, ...)
{
	va_list	ap;
	
	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}
