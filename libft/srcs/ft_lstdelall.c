/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 18:31:04 by jabadie           #+#    #+#             */
/*   Updated: 2014/12/13 18:44:18 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelall(t_chlst *lst)
{
	t_chlst	*after;

	while (lst != NULL)
	{
		after = lst->next;
		if (lst->str != NULL)
		{
			free(lst->str);
			lst->str = NULL;
		}
		free(lst);
		lst = after;
	}
}
