/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chlst_to_ch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 18:00:27 by jabadie           #+#    #+#             */
/*   Updated: 2014/12/17 18:08:59 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chlst_to_ch(t_chlst *first)
{
	char	*res;
	int		len;
	int		i2;
	t_chlst	*lst;

	len = 0;
	lst = first;
	while (lst != NULL)
	{
		len += ft_strlen(lst->str) + 1;
		lst = lst->next;
	}
	if (!(res = ft_strnew(len)))
		return (NULL);
	i2 = 0;
	lst = first;
	while (lst != NULL)
	{
		ft_strcpy(&res[i2], lst->str);
		i2 += ft_strlen(lst->str);
		ft_strcpy(&res[i2++], "/");
		lst = lst->next;
	}
	return (res);
}
