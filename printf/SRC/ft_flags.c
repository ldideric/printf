/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flags.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 01:38:37 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/12 12:15:34 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static t_spec	ft_specifier(char c)
{
	static const t_spec spec[128] = {
		['c'] = &printf_c,
		['s'] = &printf_s,
		['p'] = &printf_p,
		['d'] = &printf_di,
		['i'] = &printf_di,
		['u'] = &printf_u,
		['x'] = &printf_x,
		['X'] = &printf_x,
	};

	return (spec[(int)c]);
}

static int		ft_flagwp(char *str, t_arg *list, int a)
{
	int i;

	i = 0;
	if (a == 0)
	{
		list[0].intprec = (str[i] == '*') ? 1 : list[0].intprec;
		list[0].prec = (ft_atoi(str + i) > 0 && ft_isdigit(str[i]) == 1)
		? ft_atoi(str + i) : -1;
		i = (ft_isdigit(str[i]) == 1) ? ft_numlen(str + i) - 1 : i;
		list[0].prec = (str[i] != '*' && ft_isdigit(str[i]) == 0)
		? -1 : list[0].prec;
		i = (str[i] != '*' && ft_isdigit(str[i]) == 0) ? i - 1 : i;
		return (i + 2);
	}
	list[0].intwidth = (str[i] == '*') ? 1 : list[0].intwidth;
	list[0].width = (ft_atoi(str + i) > 0 && ft_isdigit(str[i]) == 1)
	? ft_atoi(str + i) : -1;
	i = (ft_isdigit(str[i]) == 1) ? ft_numlen(str + i) - 1 : i;
	list[0].width = (str[i] != '*' && ft_isdigit(str[i]) == 0)
	? -1 : list[0].width;
	i = (str[i] != '*' && ft_isdigit(str[i]) == 0) ? i - 1 : i;
	return (i + 1);
}

static t_arg	ft_flagcheck(char *str, t_arg list)
{
	int i;

	i = 0;
	if (str[i] == '0')
	{
		list.zero = 1;
		i++;
	}
	if (str[i] == '-')
	{
		list.minus = 1;
		i++;
	}
	if (ft_isdigit(str[i]) || str[i] == '*')
		i = i + ft_flagwp(str + i, &list, 1);
	if (str[i] == '.')
		i = i + ft_flagwp(str + i + 1, &list, 0);
	list.hex = (str[i] == 'X') ? 1 : list.hex;
	return (list);
}

// void		ft_printlist(t_arg list, char *str)
// {
// 	printf("\nstring: %s\n", str);
// 	printf("prec\t: %d\n", list.prec);
// 	printf("intprec\t: %d\n", list.intprec);
// 	printf("width\t: %d\n", list.width);
// 	printf("intwidth: %d\n", list.intwidth);
// 	printf("minus\t: %d\n", list.minus);
// 	printf("zero\t: %d\n", list.zero);
// 	printf("hex\t: %d\n\t", list.hex);
// }

int				ft_flags(char *str, va_list ap)
{
	int		i;
	t_arg	*list;
	t_spec	spec;

	i = 1;
	list = ft_argnew();
	if (str[i] == '%')
		return (ft_putchar(str[i]));
	if (ft_isalpha(str[i]) == 0)
		*list = ft_flagcheck(str + i, *list);
	while (ft_isalpha(str[i]) == 0)
		i++;
	spec = ft_specifier(str[i]);
//	ft_printlist(*list, str);
	i = spec(ap, *list);
	free(list);
	return (i);
}
