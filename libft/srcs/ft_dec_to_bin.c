/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 16:24:48 by jabadie           #+#    #+#             */
/*   Updated: 2014/12/02 17:43:45 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*dec_to_bin(uintmax_t nb)
{
	char	*bin;
	char	c;
	int		i;
	int		i2;

	bin = ft_strnew(35);
	i = 0;
	while (nb >= 2)
	{
		bin[i] = (nb % 2) + 48;
		nb /= 2;
		i++;
	}
	bin[i] = nb + 48;
	i2 = 0;
	while (i2 < i)
	{
		c = bin[i];
		bin[i] = bin[i2];
		bin[i2] = c;
		i2++;
		i--;
	}
	return (bin);
}
