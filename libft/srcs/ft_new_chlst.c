/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_chlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:33:51 by jabadie           #+#    #+#             */
/*   Updated: 2014/12/09 12:36:21 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_chlst	*new_chlst(void)
{
	t_chlst	*new;

	if (!(new = (t_chlst*)malloc(sizeof(t_chlst))))
		return (NULL);
	new->str = NULL;
	new->next = NULL;
	return (new);
}
