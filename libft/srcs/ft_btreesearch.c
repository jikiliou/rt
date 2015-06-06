/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreesearch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:27:41 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/07 17:33:39 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_btreesearch(t_btree *root, void *data_ref,
												int (*cmpf)(void *, void *))
{
	if (root->left)
		ft_btreesearch(root->left, data_ref, cmpf);
	if (root->item == data_ref)
		return (root->item);
	if (root->right)
		ft_btreesearch(root->right, data_ref, cmpf);
	return (NULL);
}
