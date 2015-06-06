/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrstrnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 21:14:41 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/10 17:56:54 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_ptrstrnew(int size)
{
	int		i;
	char	**new;

	if (!(new = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = ft_strnew(0);
		i++;
	}
	new[i] = NULL;
	return (new);
}
