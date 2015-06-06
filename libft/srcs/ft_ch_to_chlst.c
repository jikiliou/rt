/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_to_chlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 23:00:11 by jabadie           #+#    #+#             */
/*   Updated: 2014/12/17 17:33:30 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_chlst	*ft_ch_to_chlst(char **str)
{
	int		i;
	t_chlst	*new;
	t_chlst	*first;

	if (str == NULL || *str == NULL)
		return (NULL);
	if (!(new = ft_chlstnew(str[0])))
		return (NULL);
	first = new;
	i = 1;
	while (str[i] != NULL)
	{
		if (!(new->next = ft_chlstnew(str[i])))
			return (NULL);
		new = new->next;
		i++;
	}
	new->next = ft_chlstnew(NULL);
	return (first);
}
