/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:40:13 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/16 12:32:03 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_makestr(char *format, va_list ap)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			len++;
			ft_putchar(format[i]);
		}
		else if (format[i] == '%')
		{
			len = len + ft_flags(format + i, ap);
			if (format[i + 1] == '%')
				i++;
			else
				while (ft_isalpha(format[i]) == 0)
					i++;
		}
		i++;
	}
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, format);
	len = ft_makestr((char *)format, ap);
	va_end(ap);
	return (len);
}
