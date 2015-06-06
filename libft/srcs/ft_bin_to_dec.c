/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 17:03:38 by jabadie           #+#    #+#             */
/*   Updated: 2014/12/02 17:18:14 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_bin_to_dec(char *str)
{
	uintmax_t	result;
	int			len;
	int			i;

	len = ft_strlen(str) - 1;
	i = 0;
	result = 0;
	while (len > -1)
	{
		result += (str[len] - 48) * ft_pow(2, i);
		len--;
		i++;
	}
	return (result);
}
