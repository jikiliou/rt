/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 18:05:46 by jabadie           #+#    #+#             */
/*   Updated: 2014/12/08 16:12:27 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <wchar.h>
#include <libft.h>

void	print_mask(int i, int len, char *mask)
{
	int			i2;
	uintmax_t	tab[4];
	char		*tmp;

	i2 = i / 8;
	while (len < i2)
	{
		if (!(tmp = ft_strnew(8)))
			return ;
		ft_strncpy(tmp, &mask[len * 8], 8);
		tab[len] = ft_bin_to_dec(tmp);
		write(1, &tab[len], 1);
		free(tmp);
		len++;
	}
}

char	*fill_mask(char *mask, int i, int len, char *str)
{
	int	i2;

	i2 = i - 1;
	len--;
	while (len > -1)
	{
		if (mask[i2] == 'x')
			mask[i2] = str[len--];
		i2--;
	}
	i2 = i - 1;
	while (i2 > -1)
	{
		if (mask[i2] == 'x')
			mask[i2] = '0';
		i2--;
	}
	return (mask);
}

int		ft_putwchar(wchar_t c)
{
	char	*str;
	char	*mask;
	int		len;
	int		i;

	str = dec_to_bin(c);
	len = ft_strlen(str);
	if (len <= 7)
		mask = ft_strdup("0xxxxxxx");
	else if (len <= 11)
		mask = ft_strdup("110xxxxx10xxxxxx");
	else if (len <= 16)
		mask = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	else if (len <= 21)
		mask = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	else
		return (0);
	i = ft_strlen(mask);
	mask = fill_mask(mask, i, len, str);
	print_mask(i, 0, mask);
	free(mask);
	return (i / 8);
}
