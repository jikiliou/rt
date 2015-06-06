/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 21:43:52 by jabadie           #+#    #+#             */
/*   Updated: 2014/12/13 21:43:56 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*after;
	t_list	*now;

	now = *alst;
	while (now != NULL)
	{
		after = now->next;
		del(now, sizeof(t_list));
		now = after;
	}
	*alst = NULL;
}
