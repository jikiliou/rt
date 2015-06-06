/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 20:04:35 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/28 20:13:04 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "libft.h"

char	*ft_unsigned_itoa(uintmax_t nb)
{
	char	*res;
	char	c;
	int		i;
	int		i2;

	res = ft_strnew(25);
	i = 0;
	while (nb > 9)
	{
		res[i] = (nb % 10) + 48;
		nb /= 10;
		i++;
	}
	res[i] = nb + 48;
	i2 = 0;
	while (i2 < i)
	{
		c = res[i];
		res[i] = res[i2];
		res[i2] = c;
		i2++;
		i--;
	}
	return (res);
}
