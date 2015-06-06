/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 13:07:17 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/06 23:16:38 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static float	calc_poly(t_cone *cone, t_ray *ray, t_vect delta_p,
							float cos_sin[2])
{
	float	abc[3];
	float	dir_axe;
	float	d_p_axe;
	t_vect	tmp[2];
	float	dist[2];

	dir_axe = dot_product(ray->dir, cone->axe);
	d_p_axe = dot_product(delta_p, cone->axe);
	tmp[0] = sub_vect(ray->dir, mult_float(cone->axe, dir_axe));
	tmp[1] = sub_vect(delta_p, mult_float(cone->axe, d_p_axe));
	abc[0] = (cos_sin[0] * dot_product(tmp[0], tmp[0])) - (cos_sin[1] *
															pow(dir_axe, 2));
	abc[1] = 2 * cos_sin[0] * dot_product(tmp[0], tmp[1]) - (2 * cos_sin[1] *
															dir_axe * d_p_axe);
	abc[2] = cos_sin[0] * dot_product(tmp[1], tmp[1]) - (cos_sin[1] *
															pow(d_p_axe, 2));
	if ((dir_axe = abc[1] * abc[1] - (4 * abc[0] * abc[2])) < 0)
		return (-1);
	dir_axe = sqrt(dir_axe);
	abc[0] *= 2;
	dist[0] = (-abc[1] + dir_axe) / abc[0];
	dist[1] = (-abc[1] - dir_axe) / abc[0];
	if (dist[0] < 0 || dist[1] < 0)
		return (-1);
	return (dist[0] < dist[1] ? dist[0] : dist[1]);
}

static t_vect	calc_normal(t_cone *cone, t_vect pos)
{
	t_vect	normal;
	float	sinus;

	normal = sub_vect(pos, cone->o);
	sinus = sin(RAD(cone->alpha));
	if (cone->axe.y == 1)
		normal.y = sqrt(pow(normal.x, 2) + pow(normal.z, 2)) * sinus;
	else if (cone->axe.x == 1)
		normal.x = sqrt(pow(normal.y, 2) + pow(normal.z, 2)) * sinus;
	else if (cone->axe.z == 1)
		normal.z = sqrt(pow(normal.y, 2) + pow(normal.x, 2)) * sinus;
	return (normal);
}

float			inter_cone(t_obj *object, t_ray *ray, t_inter *inter)
{
	t_cone	*cone;
	float	tmp;
	t_vect	pos;

	cone = (t_cone*)object->obj;
	tmp = calc_poly(cone, ray, sub_vect(ray->o, cone->o), cone->cos_sin);
	if (tmp != -1)
	{
		pos = add_vect(ray->o, mult_float(ray->dir, tmp));
		tmp = magnitude(sub_vect(pos, ray->o));
		if (inter->dist == -1 || tmp < inter->dist)
		{
			inter->pos = pos;
			inter->normal = calc_normal(cone, pos);
			inter->dist = tmp;
			inter->obj = object;
		}
	}
	return (tmp);
}
