/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:04:13 by jabadie           #+#    #+#             */
/*   Updated: 2015/03/25 14:26:08 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == LONG_MIN)
		{
			write(1, "-9223372036854775808", 21);
			return ;
		}
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}
