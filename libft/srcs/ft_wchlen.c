/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 17:43:11 by jabadie           #+#    #+#             */
/*   Updated: 2014/12/05 17:46:14 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

int	ft_wchlen(wchar_t c)
{
	int		count;
	char	*str;
	int		len;

	count = 0;
	str = dec_to_bin(c);
	len = ft_strlen(str);
	if (len <= 7)
		count = 1;
	else if (len <= 11)
		count = 2;
	else if (len <= 16)
		count = 3;
	else if (len <= 21)
		count = 4;
	return (count);
}
