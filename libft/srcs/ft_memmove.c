/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:45:31 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/05 18:41:58 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*buf;

	i = 0;
	if (!(buf = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (i < len)
	{
		buf[i] = ((char*)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((char*)dst)[i] = buf[i];
		i++;
	}
	return (dst);
}
