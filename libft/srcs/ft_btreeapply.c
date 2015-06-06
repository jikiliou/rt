/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeapply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:26:18 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/07 17:26:20 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeapply(t_btree *root, void (*applyf)(void *))
{
	if (root)
		applyf(root);
	if (root->left)
		ft_btreeapply(root->left, applyf);
	if (root->right)
		ft_btreeapply(root->right, applyf);
}
