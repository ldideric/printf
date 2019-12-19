/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:40:13 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/19 18:51:34 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_makestr(char *format, va_list ap, int len, int i)
{
	int temp;

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			len++;
			ft_putchar(format[i]);
		}
		else if (format[i] == '%')
		{
			temp = len;
			len = len + ft_flags(format + i, ap);
			i++;
			if (temp != len)
				while (ft_isalpha(format[i]) == 0 && format[i] != '%'
				&& format[i] != '\0')
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
	len = ft_makestr((char *)format, ap, 0, 0);
	va_end(ap);
	return (len);
}
