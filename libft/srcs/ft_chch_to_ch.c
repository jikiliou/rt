/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chch_to_ch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 17:53:14 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/09 11:15:14 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chch_to_ch(char **str)
{
	char	*res;
	int		len;
	int		i;
	int		i2;

	len = 0;
	i = 0;
	while (str[i] != NULL)
	{
		len += ft_strlen(str[i]);
		i++;
	}
	if (!(res = ft_strnew(len)))
		return (NULL);
	i = 0;
	i2 = 0;
	while (str[i] != NULL)
	{
		ft_strcpy(&res[i2], str[i]);
		i2 += ft_strlen(str[i]);
		i++;
	}
	return (res);
}
