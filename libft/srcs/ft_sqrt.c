/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:33:44 by jabadie           #+#    #+#             */
/*   Updated: 2015/03/26 11:10:44 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			fill_two_nb(long int nb, int *two_nb, int len)
{
	int	i;

	i = 1;
	while (i <= len)
	{
		two_nb[len - i] = nb - (nb / 100 * 100);
		nb = (nb - two_nb[len - i]) / 100;
		i++;
	}
}

static void			part_calc(long int nb, long int *res, int two_nb_size,
							int f)
{
	int				two_nb[two_nb_size];
	int				i;
	int				tmp;
	static long int	solve_me = 0;

	fill_two_nb(nb, two_nb, two_nb_size);
	i = 0;
	if (f == 1)
		solve_me = 0;
	while (i < two_nb_size)
	{
		solve_me = solve_me * 100 + two_nb[i];
		tmp = 0;
		while (((20 * *res + tmp + 1) * (tmp + 1)) <= solve_me)
			tmp++;
		solve_me -= (20 * *res + tmp) * tmp;
		*res = *res * 10 + tmp;
		i++;
	}
}

static long double	calc_sqrt(long int *sep_nb)
{
	long double	ret;
	long int	res;
	int			size;
	int			dot_place;

	res = 0;
	size = ft_nblen(sep_nb[0]) / 2 + ft_nblen(sep_nb[0]) % 2;
	part_calc(sep_nb[0], &res, size, 1);
	dot_place = ft_nblen(res);
	if (sep_nb[1] == 0)
		size = 6;
	else
		size = ft_nblen(sep_nb[1]) / 2 + ft_nblen(sep_nb[1]) % 2;
	part_calc(sep_nb[1], &res, size, 0);
	ret = (long double)res / ft_pow(10, ft_nblen(res) - dot_place);
	return (ret);
}

long double			ft_sqrt(long double nb)
{
	long int	*sep_nb;
	long double	ret;

	sep_nb = float_to_int(nb, 12);
	ret = calc_sqrt(sep_nb);
	free(sep_nb);
	return (ret);
}
