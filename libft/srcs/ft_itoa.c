/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:50:01 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/30 12:35:21 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static char	*fill_it(char *good_tab, intmax_t n, int i2)
{
	char	tab[21];
	int		i;

	i = 0;
	while (n > 0)
	{
		tab[i] = (n % 10) + 48;
		n = (n - (n % 10)) / 10;
		i++;
	}
	i--;
	while (i >= 0)
		good_tab[i2++] = tab[i--];
	good_tab[i2] = '\0';
	return (good_tab);
}

char		*ft_itoa(intmax_t n)
{
	char		*good_tab;
	uintmax_t	n2;
	int			i2;

	if (!(good_tab = ft_strnew(21)))
		return (NULL);
	i2 = 0;
	if (n < 0)
	{
		good_tab[i2++] = '-';
		n2 = n * -1;
		good_tab = ft_strmore(good_tab, ft_unsigned_itoa(n2));
		return (good_tab);
	}
	if (n == 0)
		return (ft_strcpy(good_tab, "0\0"));
	good_tab = fill_it(good_tab, n, i2);
	return (good_tab);
}
