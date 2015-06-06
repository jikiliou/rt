/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:58:59 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/08 14:36:13 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	i2;
	int		len;

	i = 0;
	len = ft_strlen(s2);
	if (n == 0)
		return (NULL);
	while (s1[i] && i < n)
	{
		i2 = 0;
		while (s1[i + i2] == s2[i2] && i + i2 < n && s2[i2])
			i2++;
		if ((int)i2 == len)
			return ((char*)&s1[i]);
		i++;
	}
	if (i == n)
		return (NULL);
	if (s1[i] == '\0' && s2[0] == '\0')
		return ((char*)&s1[i]);
	return (NULL);
}
