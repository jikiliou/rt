/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 10:45:17 by jabadie           #+#    #+#             */
/*   Updated: 2015/03/27 12:11:53 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat(long double nb)
{
	long int *res;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	res = float_to_int(nb, 6);
	ft_putnbr(res[0]);
	if (res[1] != 0)
	{
		ft_putchar('.');
		ft_putnbr(res[1]);
	}
	free(res);
}
