/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 22:29:52 by jabadie           #+#    #+#             */
/*   Updated: 2015/05/01 12:24:34 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	draw_pixel(t_color color, t_pict *pict)
{
	(*pict->data++) = color.b;
	(*pict->data++) = color.g;
	(*pict->data++) = color.r;
	(*pict->data++) = 0;
}
