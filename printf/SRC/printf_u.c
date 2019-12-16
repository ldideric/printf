/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_u.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 13:47:07 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/09 15:58:39 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_u_ext(char *str, t_arg list, char c)
{
	int i;

	i = 0;
	if (*str == '-')
	{
		ft_putchar(str[0]);
		list.width--;
		i++;
		str++;
	}
	while (list.width > (int)ft_strlen(str))
	{
		ft_putchar(c);
		i++;
		list.width--;
	}
	while (*str)
	{
		ft_putchar(*str);
		str++;
		i++;
	}
	return (i);
}

int			printf_u(va_list ap, t_arg list)
{
	int		i;
	char	c;
	char	*str;

	i = 0;
	c = (list.zero) ? '0' : ' ';
	if (list.intprec)
		list.prec = va_arg(ap, int);
	if (list.intwidth)
		list.width = va_arg(ap, int);
	str = ft_itoa_base(va_arg(ap, unsigned int), 10, 0);
	if (list.width)
		i = printf_u_ext(str, list, c);
	else
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	return (i);
}
