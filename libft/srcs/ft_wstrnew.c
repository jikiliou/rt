/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:50:22 by jabadie           #+#    #+#             */
/*   Updated: 2014/12/02 18:46:58 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>

wchar_t	*ft_wstrnew(int size)
{
	wchar_t	*new;
	int		i;

	if (!(new = (wchar_t*)malloc(sizeof(wchar_t) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size + 1)
		new[i++] = '\0';
	return (new);
}
