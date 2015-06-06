/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:39:40 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/06 16:42:32 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		i2;

	i = 0;
	while (s1[i])
	{
		i2 = 0;
		while (s1[i + i2] == s2[i2] && s2[i2])
			i2++;
		if (i2 == ft_strlen(s2))
			return ((char*)&s1[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[0] == '\0')
		return ((char*)&s1[i]);
	return (NULL);
}
