/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:49:33 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/08 14:27:56 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*zone;
	size_t	i;

	if (size)
	{
		if (!(zone = malloc(sizeof(void) * size)))
			return (NULL);
		i = 0;
		while (i < size)
		{
			((char*)zone)[i] = 0;
			i++;
		}
		return (zone);
	}
	return (NULL);
}
