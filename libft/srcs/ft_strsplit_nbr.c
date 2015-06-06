/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:20:31 by jabadie           #+#    #+#             */
/*   Updated: 2014/12/13 21:41:55 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		is_delim(char c)
{
	if (!('0' <= c && c <= '9'))
		return (1);
	return (0);
}

t_chlst			*ft_strsplit_nbr(char *str, int i)
{
	int		i2;
	t_chlst	*lst;
	t_chlst	*first;

	if (!(lst = new_chlst()))
		return (NULL);
	first = lst;
	while (str[i] != '\0')
	{
		if (i != 0)
		{
			lst->next = new_chlst();
			lst = lst->next;
		}
		while (is_delim(str[i]) == 1 && str[i] != '\0')
			i++;
		i2 = i;
		while (is_delim(str[i]) == 0)
			i++;
		if (!(lst->str = ft_strnew(i - i2)))
			return (NULL);
		ft_strncpy(lst->str, &str[i2], i - i2);
	}
	return (first);
}
