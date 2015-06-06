/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:27:09 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/07 17:04:04 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*cre_lst(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new = f(lst);
	return (new);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*now;
	t_list	*first;

	if (lst != NULL)
	{
		if (!(now = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		now = f(lst);
		first = now;
		lst = lst->next;
	}
	while (lst != NULL)
	{
		now->next = cre_lst(lst, f);
		lst = lst->next;
		now = now->next;
	}
	return (first);
}
