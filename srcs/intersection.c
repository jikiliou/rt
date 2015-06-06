/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 21:44:22 by jabadie           #+#    #+#             */
/*   Updated: 2015/05/01 18:12:03 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

float	calc_polynomial(t_sphere *sphere, t_ray *ray)
{
	float	b;
	float	c;
	float	delta;
	float	t;
	t_vect	tmp_ray;

	tmp_ray = sub_vect(ray->o, sphere->c);
	b = dot_product(tmp_ray, ray->dir);
	c = magnitude(tmp_ray) - (sphere->r * sphere->r);
	delta = b * b - c;
	if (delta < 0)
		return (-1);
	if (delta == 0)
		return (-b);
	delta = sqrt(delta);
	t = -b + delta;
	c = -b - delta;
	if (t < 0 || c < 0)
		return (-1);
	return (t < c ? t : c);
}

float	inter_sphere(void *obj, t_ray *ray, t_inter *inter)
{
	t_sphere	*sphere;
	t_vect		pos;
	float		tmp;
	float		tmp_dist;

	sphere = (t_sphere*)obj;
	tmp = calc_polynomial(sphere, ray);
	if (tmp != -1)
	{
		pos = add_vect(ray->o, mult_float(ray->dir, tmp));
		tmp_dist = magnitude(sub_vect(pos, ray->o));
		if (inter->dist == -1 || tmp_dist < inter->dist)
		{
			inter->pos = pos;
			inter->normal = div_float(sub_vect(inter->pos, sphere->c),
											sphere->r);
		}
	}
	return (tmp);
}

float	inter_plan(void *obj, t_ray *ray, t_inter *inter)
{
	t_plan	*plan;
	float	t;
	float	dv;
	t_vect	pos;
	float	tmp;

	plan = (t_plan*)obj;
	if ((dv = dot_product(plan->normal, ray->dir)) == 0)
		return (-1);
	t = (dot_product(plan->normal, sub_vect(ray->o, plan->pos)) * -1) / dv;
	if (t < 0)
		return (-1);
	pos = add_vect(ray->o, mult_float(ray->dir, t));
	tmp = magnitude(sub_vect(pos, ray->o));
	if (inter->dist == -1 || tmp < inter->dist)
	{
		inter->pos = pos;
		if (dv < 0)
			inter->normal = plan->normal;
		else
			inter->normal = mult_float(plan->normal, -1);
	}
	return (t);
}
