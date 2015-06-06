/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 16:42:35 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/06 17:27:35 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_color		reflection(t_scene *scene, t_inter *inter, t_color pixel_color, int level)
{
	t_color	reflec;
	t_ray	ray;

	if (level >= MAX_REFLEC)
		return (pixel_color);
	if (inter->obj->mat->reflec > 0)
	{
		ray.o = inter->pos;
		ray.dir = inter->reflect;
		reflec = ray_go_to_the_world_and_dont_forget_to_draw(scene, &ray, level + 1);
		reflec = add_color(mult_color(reflec, inter->obj->mat->reflec),
							mult_color(pixel_color, (1 - inter->obj->mat->reflec)));
	}
	else
		reflec = pixel_color;
	return (reflec);
}
