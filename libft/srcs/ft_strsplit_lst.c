/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:24:57 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/09 11:15:24 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		help_split(char *str, int i, char c)
{
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

t_chlst	*ft_strsplit_lst(char *str, char c)
{
	t_chlst	*lst;
	t_chlst	*first;
	int		i;
	int		i2;

	if (str == NULL || !(lst = ft_chlstnew(NULL)))
		return (NULL);
	first = lst;
	i = 0;
	while (str[i] != '\0')
	{
		if (i != 0)
		{
			if (!(lst->next = ft_chlstnew(NULL)))
				return (NULL);
			lst = lst->next;
		}
		i2 = help_split(str, i, c);
		lst->str = ft_strnew(i2 - i + 1);
		ft_strncpy(lst->str, &str[i], i2 - i);
		i = i2;
		if (str[i] != '\0')
			i++;
	}
	return (first);
}
