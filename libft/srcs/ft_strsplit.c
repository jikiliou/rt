/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:20:31 by jabadie           #+#    #+#             */
/*   Updated: 2015/05/01 16:26:49 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int		is_delim(char c, char cara)
{
	if (c == cara)
		return (1);
	return (0);
}

static int		find_nb_words(char *str, char cara)
{
	int result;

	result = 0;
	while (*str)
	{
		while (is_delim(*str, cara))
			str++;
		if (*str)
			result++;
		while (!is_delim(*str, cara) && *str)
			str++;
	}
	return (result);
}

static char		**split_func(char *str, int nb_words, int *i, char cara)
{
	int		i3;
	int		word_size;
	char	**result;

	if (!(result = malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	while (i[0] < nb_words)
	{
		while (is_delim(str[i[1]], cara))
			i[1]++;
		word_size = 0;
		while (!is_delim(str[i[1] + word_size], cara) && str[i[1] + word_size])
			word_size++;
		if (!(result[i[0]] = malloc(sizeof(char) * (word_size + 1))))
			return (NULL);
		i3 = -1;
		while (++i3 < word_size)
			result[i[0]][i3] = str[i[1] + i3];
		result[i[0]][i3] = '\0';
		i[1] += word_size;
		i[0]++;
	}
	result[i[0]] = (NULL);
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	int i[2];

	if (s && c)
	{
		i[0] = 0;
		i[1] = 0;
		return (split_func((char*)s, find_nb_words((char*)s, c), i, c));
	}
	return (NULL);
}
