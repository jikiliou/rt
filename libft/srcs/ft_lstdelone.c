/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:59:23 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/07 16:16:18 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*now;

	now = *alst;
	if (*alst != NULL)
	{
		del(now->content, sizeof(now->content));
		now->content = NULL;
		free(now);
		*alst = NULL;
	}
}
