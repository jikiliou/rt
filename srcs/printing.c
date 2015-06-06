/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 20:34:55 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/04 06:55:17 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_pict	*fill_pict(void)
{
	t_pict	*new;

	if (!(new = (t_pict*)malloc(sizeof(t_pict))))
		ft_error("MALLOC ERROR IN FILL PICT", NULL);
	if (!(new->mlx = mlx_init()))
		ft_error("MLX INIT ERROR", NULL);
	if (!(new->win = mlx_new_window(new->mlx, WIN_X, WIN_Y, "Raytracer")))
		ft_error("MLX NEW WINDOW ERROR", NULL);
	if (!(new->pic = mlx_new_image(new->mlx, WIN_X, WIN_Y)))
		ft_error("MLX NEW IMAGE ERROR", NULL);
	new->data = mlx_get_data_addr(new->pic, &new->bpp, &new->sz, &new->endian);
	return (new);
}

void	draw_pixel(t_color color, t_pict *pict)
{
	(*pict->data++) = color.b;
	(*pict->data++) = color.g;
	(*pict->data++) = color.r;
	(*pict->data++) = 0;
}
