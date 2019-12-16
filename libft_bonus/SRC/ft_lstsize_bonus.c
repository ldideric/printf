/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 19:24:57 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/02 18:56:32 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

int		ft_lstsize(t_list *lst)
{
	int i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
