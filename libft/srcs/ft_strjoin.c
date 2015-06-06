/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:28:58 by jabadie           #+#    #+#             */
/*   Updated: 2015/03/16 03:19:11 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	int		i;
	int		i2;

	if (s1 && s2)
	{
		i = 0;
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		if (!(str = (char*)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
			return (NULL);
		i2 = 0;
		while (i2 < len_s1)
			str[i++] = s1[i2++];
		i2 = 0;
		while (i2 < len_s2)
			str[i++] = s2[i2++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
