/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_x.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 13:48:42 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/09 15:58:42 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			printf_x(va_list ap, t_arg list)
{
	char	*str;
	int		i;

	i = (list.hex) ? 1 : 0;
	str = ft_itoa_base(va_arg(ap, long long), 16, i);
	i = 0;
	if (list.intprec)
		list.prec = va_arg(ap, int);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
