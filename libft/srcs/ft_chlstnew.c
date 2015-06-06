/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chlstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 22:56:27 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/10 19:39:53 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_chlst	*ft_chlstnew(char *str)
{
	t_chlst	*new;

	if (!(new = (t_chlst*)malloc(sizeof(t_chlst))))
		return (NULL);
	if (str == NULL)
		new->str = NULL;
	else
		new->str = ft_strdup(str);
	new->next = NULL;
	return (new);
}
