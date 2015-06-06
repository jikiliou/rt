/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:26:06 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/07 17:26:09 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_btree	*ft_btreenew(void *item)
{
	t_btree *tmp;

	if (!(tmp = (t_btree*)malloc(sizeof(t_btree))))
		return (NULL);
	tmp->item = item;
	tmp->right = NULL;
	tmp->left = NULL;
	return (tmp);
}
