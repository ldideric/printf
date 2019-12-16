/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_di.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 17:05:39 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/16 11:14:58 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*printf_di_str(char *s, t_arg list, char *new, int p)
{
	int slen;
	int i;

	i = 0;
	new = ft_strjoin(new, (s[0] == '-' && p == 1) ? "-" : "");
	slen = (s[0] == '-') ? ft_strlen(s) - 1 : ft_strlen(s);
	if (list.prec > slen)
	{
		while (i < list.prec - slen)
		{
			new = ft_strjoin(new, "0");
			i++;
		}
		if (s[i - (list.prec - slen)] && i < list.prec)
			new = ft_strjoin(new, ft_substr(s, 1, ft_strlen(s) - 1));
	}
	else
		new = ft_strjoin(new, s + i);
	return (new);
}

static char	*printf_di_width(char *s, t_arg list, char *new, int p)
{
	int		slen;
	int		len;
	char	*c;

	slen = ((int)ft_strlen(s) > list.prec) ? ft_strlen(s) : list.prec;
	slen = (s[0] == '-' && list.prec > (int)ft_strlen(s)) ? slen + 1 : slen;
	new = ft_strjoin(new, (s[0] == '-' && p == 1 && list.width < slen) ? "-" : "");
	new[(ft_strlen(new) - 1 >= 0) ? ft_strlen(new) - 1 : 0] = (list.zero) ? '-' : '\0';
	len = (list.width > slen) ? list.width - slen : 0;
	c = (list.zero) ? "0" : " ";
	while (len > 0)
	{
		new = ft_strjoin(new, c);
		len--;
	}
	return (new);
}

static char	*printf_di_ext(char *s, t_arg list)
{
	char	*new;

	new = "";
	if (list.minus)
		new = ft_strjoin(printf_di_str(s, list, new, 1), printf_di_width(s, list, new, 2));
	else if (!list.minus)
		new = ft_strjoin(printf_di_width(s, list, new, 1), printf_di_str(s, list, new, 2));
	return (new);
}

int			printf_di(va_list ap, t_arg list)
{
	char	*str;
	int		i;

	i = 0;
	list.width = (list.intwidth) ? va_arg(ap, int) : list.width;
	list.prec = (list.intprec) ? va_arg(ap, int) : list.prec;
	str = ft_itoa_base(va_arg(ap, int), 10, 0);
	str = printf_di_ext(str, list);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
