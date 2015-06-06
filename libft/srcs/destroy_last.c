/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 20:02:37 by jabadie           #+#    #+#             */
/*   Updated: 2014/12/17 20:03:17 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		destroy_last(t_chlst *lst)
{
	t_chlst	*tmp;

	if (lst == NULL)
		return (-1);
	tmp = NULL;
	while (lst->next != NULL)
	{
		tmp = lst;
		lst = lst->next;
	}
	free(lst);
	if (tmp != NULL)
		tmp->next = NULL;
	else
	{
		lst = NULL;
		return (-1);
	}
	return (0);
}
