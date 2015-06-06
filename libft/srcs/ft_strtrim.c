/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:37:29 by jabadie           #+#    #+#             */
/*   Updated: 2015/03/26 10:14:52 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	ft_chr(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int	*ft_index(char *s)
{
	int	*tab;
	int	i;

	if (!(tab = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	i = 0;
	tab[0] = 0;
	tab[1] = ft_strlen(s);
	while (ft_chr(s[i]) && s[i])
	{
		tab[0]++;
		i++;
	}
	i = ft_strlen(s) - 1;
	while (ft_chr(s[i]) && i >= 0)
	{
		tab[1]--;
		i--;
	}
	return (tab);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		i2;
	int		len;
	int		*tab;

	if (s)
	{
		len = ft_strlen(s);
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i2 = 0;
		tab = ft_index((char*)s);
		i = tab[0];
		while (s[i] && i < tab[1])
		{
			str[i2] = s[i];
			i2++;
			i++;
		}
		free(tab);
		str[i2] = '\0';
		return (str);
	}
	return (NULL);
}
