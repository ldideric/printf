/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_p.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 13:45:17 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/16 14:19:34 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_p_width(t_arg list, char *s)
{
	int	len;
	int i;

	i = 0;
	len = (list.width > (int)ft_strlen(s) + 2) ? list.width - ((int)ft_strlen(s) + 2) : 0;
	while (len > 0)
	{
		ft_putchar(' ');
		i++;
		len --;
	}
	return (i);
}

int			printf_p(va_list ap, t_arg list)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	list.width = (list.intwidth) ? va_arg(ap, int) : list.width;
	list.prec = (list.intprec) ? va_arg(ap, int) : list.prec;
	str = ft_itoa_base((unsigned long)va_arg(ap, void *), 16, 0);
	str = (ft_strncmp(str, "0", 3) == 0 && list.prec < 0) ? "" : str;
	if (list.width && !list.minus)
		len = len + printf_p_width(list, str);
	ft_putstr("0x");
	len = len + 2;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	if (list.width && list.minus)
		len = len + printf_p_width(list, str);
	return (i + len);
}
