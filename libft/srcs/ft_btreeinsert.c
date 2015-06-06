/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeinsert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:26:54 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/07 17:29:44 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_btreeinsert(t_btree **root, void *item,
												int (*cmpf)(void *, void *))
{
	t_btree	*tmp;

	tmp = *root;
	if (tmp == NULL)
		tmp = ft_btreenew(item);
	else if (cmpf(item, tmp->item) < 0)
		ft_btreeinsert(&tmp->left, item, cmpf);
	else if (cmpf(item, tmp->item) >= 0)
		ft_btreeinsert(&tmp->right, item, cmpf);
}
