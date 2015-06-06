/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 16:08:59 by jabadie           #+#    #+#             */
/*   Updated: 2015/03/25 18:07:00 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_error(char *str, char *str2)
{
	ft_putstr_fd(str, 2);
	if (str2 != NULL)
		ft_putstr_fd(str2, 2);
	ft_putchar('\n');
	exit(-1);
}
