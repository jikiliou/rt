/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 02:39:13 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/07 01:51:28 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_color	add_color(t_color final, t_color other)
{
	final.r += other.r;
	final.g += other.g;
	final.b += other.b;
	if (final.r > 255)
		final.r = 255;
	if (final.g > 255)
		final.g = 255;
	if (final.b > 255)
		final.b = 255;
	return (final);
}

t_color	mult_color(t_color color, float nb)
{
	t_color	res;

	res.r = color.r * nb;
	res.g = color.g * nb;
	res.b = color.b * nb;
	if (res.r > 255)
		res.r = 255;
	if (res.g > 255)
		res.g = 255;
	if (res.b > 255)
		res.b = 255;
	return (res);
}

t_color	init_color(int r, int g, int b)
{
	t_color	tmp;

	tmp.r = r;
	tmp.g = g;
	tmp.b = b;
	return (tmp);
}

t_color	color_type(float angle, float coef, t_color obj_color, t_coef light_color)
{
	t_color	color;

	if (angle <= 0)
		color = init_color(0, 0, 0);
	else
	{
		color = mult_color(obj_color, coef * angle);
		color.r *= light_color.r;
		color.g *= light_color.g;
		color.b *= light_color.b;	
	}
	return (color);
}

t_color	specular_color(t_inter *inter, t_ray *light_ray, t_light *light,
		t_ray *ray)
{
	t_color		color;
	float		angle;
	t_vect		reflect;

	reflect = sub_vect(light_ray->dir, mult_float(inter->normal,
				2 * dot_product(inter->normal, light_ray->dir)));
	angle = dot_product(reflect, mult_float(ray->dir, -1));
	if (angle > 0)
		angle = pow(angle, inter->obj->mat->spec_coef * 150);
	color = color_type(angle, inter->obj->mat->spec_coef, init_color(255, 255, 255), light->coef_color);
	return (color);
}

t_color	calc_color(t_inter *inter, t_ray *light_ray, t_light *light,
		t_ray *ray)
{
	t_color	color;
	t_vect	light_dir;
	float	angle;

	light_dir = vect(-light_ray->dir.x, -light_ray->dir.y, -light_ray->dir.z);
	norm_vect(&inter->normal);
	angle = dot_product(inter->normal, light_dir);
	color = color_type(angle, inter->obj->mat->diff_coef, inter->obj->color, light->coef_color);
	if (inter->obj->type != PLAN)
			color = add_color(color, specular_color(inter, light_ray, light, ray));
	return (color);
}

t_color	ambiant_color(t_light *light, t_inter *inter)
{
	t_color	color;
	float	intensity;

	intensity = ((float)light->intensity / 7);
	color.r = inter->obj->mat->amb_coef * inter->obj->color.r * intensity * light->coef_color.r;
	color.g = inter->obj->mat->amb_coef * inter->obj->color.g * intensity * light->coef_color.g;
	color.b = inter->obj->mat->amb_coef * inter->obj->color.b * intensity * light->coef_color.b;
	return (color);
}


