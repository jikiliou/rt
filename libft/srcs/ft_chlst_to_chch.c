/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chlst_to_chch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:20:23 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/11 10:21:45 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_chlst_to_chch(t_chlst *lst)
{
	int		len;
	int		i;
	char	**str;

	len = ft_lstlen(lst);
	if (!(str = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	i = 0;
	while (lst != NULL)
	{
		if (lst->str != NULL)
			str[i] = ft_strdup(lst->str);
		i++;
		lst = lst->next;
	}
	str[i] = NULL;
	return (str);
}
