/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 16:01:12 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/02 18:57:03 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	list = *lst;
	temp = NULL;
	while (list)
	{
		temp = list->next;
		del(list->content);
		free(list);
		list = temp;
	}
	*lst = NULL;
}
