/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 16:20:51 by ldideric       #+#    #+#                */
/*   Updated: 2020/01/09 10:59:59 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
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
	printf(FIRST, printf(REAL) - 50);
	ft_printf(FIRST, ft_printf(MINE) - 50);
	return (0);
}
