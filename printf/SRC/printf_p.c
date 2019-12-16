/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_p.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 13:45:17 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/09 15:58:34 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			printf_p(va_list ap, t_arg list)
{
	unsigned long	value;
	char			*str;
	char			c;
	int				i;

	i = 0;
	c = (list.zero) ? '0' : ' ';
	value = (unsigned long)va_arg(ap, void *);
	str = malloc(ft_intchars(value, 16) + 3);
	str = ft_strjoin("0x", ft_itoa_base(value, 16, 0));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
