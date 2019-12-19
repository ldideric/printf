/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 16:00:29 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/19 19:54:20 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** c = character
** s = string
** p = pointer adress
** d = signed integer (dec)
** i = signed integer (dec)
** u = unsigned integer (dec)
** x = unsigned integer (hex)
** X = unsigned integer (hex) (CAPS)
** % = '%'
*/
/*
** .#	= precision (chars written)
** .*	= precision but as integer
** #	= width (spaces before)
** *	= width but as another integer
** -	= width but spaces after
** 0	= width but spaces are zeroes
*/

int		main(void)
{
	char *s;

	s = "lolol";
	printf(FIRST, printf(REAL) - 50);
	ft_printf(FIRST, ft_printf(MINE) - 50);
	return (0);
}
