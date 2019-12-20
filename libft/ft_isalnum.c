/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:50:50 by ldideric       #+#    #+#                */
/*   Updated: 2019/11/16 17:06:07 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	else
		return (0);
}
