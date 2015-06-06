/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:33:15 by jabadie           #+#    #+#             */
/*   Updated: 2015/03/23 05:44:05 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_pow(int nb, int power)
{
	long int result;

	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		result *= nb;
		power--;
	}
	return (result);
}
