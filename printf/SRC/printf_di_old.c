/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_di_old.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:18:23 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/12 19:38:06 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_di_minus(char *s, t_arg list)
{
	int i;

	i = 0;
	ft_putchar(s[0]);
	if (list.prec > ((int)ft_strlen(s) - 1))
	{
		while (i < list.prec - ((int)ft_strlen(s) - 1))
		{
			ft_putchar('0');
			i++;
		}
		while (s[i - (list.prec - (int)ft_strlen(s))] && i < list.prec)
		{
			ft_putchar(s[i - (list.prec - (int)ft_strlen(s))]);
			i++;
		}
	}
	else
		while (s[i + 1])
		{
			ft_putchar(s[i + 1]);
			i++;
		}
	return (i + 1);
}

static int	printf_di_str(char *s, t_arg list)
{
	int i;

	i = 0;
	i = (s[0] == '-' && !list.width) ? printf_di_minus(s, list): i;
	s = (list.width) ? ft_substr(s, 1, ft_strlen(s) - 1) : s;
	if (list.prec > (int)ft_strlen(s))
	{
		while (i < list.prec - (int)ft_strlen(s))
		{
			ft_putchar('0');
			i++;
		}
		while (s[i - (list.prec - (int)ft_strlen(s))] && i < list.prec)
		{
			ft_putchar(s[i - (list.prec - (int)ft_strlen(s))]);
			i++;
		}
	}
	else
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	return (i);
}

static int	printf_di_width(char *s, t_arg list)
{
	int		len;
	int		slen;
	char	c;

	slen = (s[0] == '-' && list.prec > (int)ft_strlen(s) - 1) ? slen + 1 : slen;
	len = (list.width > slen) ? list.width - slen : 0;
	c = (list.zero) ? '0' : ' ';
	if (s[0] == '-')
		ft_putchar(s[0]);
	while (len > 0)
	{
		ft_putchar(c);
		len--;
	}
	len = (list.width > slen) ? list.width - slen : 0;
	len = (s[0] == '-') ? len + 1 : len;
	return (len);
}

static int	printf_di_ext(va_list ap, t_arg list)
{
	char	*s;
	int		i;

	i = 0;
	list.width = (list.intwidth) ? va_arg(ap, int) : list.width;
	list.prec = (list.intprec) ? va_arg(ap, int) : list.prec;
	s = ft_itoa_base(va_arg(ap, int), 10, 0);
	i = (list.width && list.minus) ? i + printf_di_str(s, list) + printf_di_width(s, list) : i;
	i = (list.width && !list.minus) ? i + printf_di_width(s, list) + printf_di_str(s, list) : i;
	i = ((!list.width && !list.minus) || (!list.width && list.minus)) ? i + printf_di_str(s, list) : i;
	if (s != NULL)
		free(s);
	return (i);
}

int			printf_di(va_list ap, t_arg list)
{
	char	*str;
	int		i;

	i = 0;
	if (list.intprec || list.prec || list.width || list.intwidth)
		i = printf_di_ext(ap, list);
	else
	{
		str = ft_itoa_base(va_arg(ap, int), 10, 0);
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
		if (str != NULL)
			free(str);
	}
	return (i);
}
