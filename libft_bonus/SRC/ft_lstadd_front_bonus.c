/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 17:55:37 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/02 18:57:08 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	new->next = *alst;
	*alst = new;
}
