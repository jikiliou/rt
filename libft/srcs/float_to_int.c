/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 05:22:33 by jabadie           #+#    #+#             */
/*   Updated: 2015/03/26 11:10:30 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	*float_to_int(long double real, int prec)
{
	long int	*res;

	if (!(res = (long int*)malloc(sizeof(long int) * 2)))
		return (NULL);
	if (prec > 14)
		prec = 14;
	res[0] = (long int)real;
	res[1] = (long int)((real - res[0]) * ft_pow(10, prec));
	if (res[1] < 0)
		res[1] = -res[1];
	return (res);
}
