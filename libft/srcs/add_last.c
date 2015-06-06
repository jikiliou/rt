/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 20:03:31 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/11 10:08:12 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_last(t_chlst *lst, char *str)
{
	while (lst->next != NULL)
		lst = lst->next;
	if (!(lst->next = ft_chlstnew(str)))
		exit(-1);
}

void	add_before_last(t_chlst *lst, char *str)
{
	t_chlst	*tmp;

	if (lst->next == NULL || lst->next->next == NULL)
	{
		add_last(lst, str);
		return ;
	}
	while (lst->next->next != NULL)
	{
		tmp = lst;
		lst = lst->next;
	}
	if (!(tmp->next = ft_chlstnew(str)))
		exit(-1);
	tmp->next->next = lst;
}
