/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 10:45:03 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/07 01:50:49 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static float	calc_poly(t_cylindre *cylindre, t_ray *ray)
{
	float	abc[3];
	float	delta;
	t_vect	delta_p;
	float	dot_pro[2];
	t_vect	tmp[2];

	delta_p = sub_vect(ray->o, cylindre->o);
	dot_pro[0] = dot_product(ray->dir, cylindre->axe);
	dot_pro[1] = dot_product(delta_p, cylindre->axe);
	tmp[0] = sub_vect(ray->dir, mult_float(cylindre->axe, dot_pro[0]));
	tmp[1] = sub_vect(delta_p, mult_float(cylindre->axe, dot_pro[1]));
	abc[0] = dot_product(tmp[0], tmp[0]);
	abc[1] = 2 * dot_product(tmp[0], tmp[1]);
	abc[2] = dot_product(tmp[1], tmp[1]) - pow(cylindre->r, 2);
	delta = abc[1] * abc[1] - (4 * abc[0] * abc[2]);
	if (delta < 0)
		return (-1);
	delta = sqrt(delta);
	abc[0] *= 2;
	dot_pro[0] = (-abc[1] + delta) / abc[0];
	dot_pro[1] = (-abc[1] - delta) / abc[0];
	if (dot_pro[0] < 0 || dot_pro[1] < 0)
		return (-1);
	return (dot_pro[0] < dot_pro[1] ? dot_pro[0] : dot_pro[1]);
}

static	t_vect	calc_normal(t_cylindre *cyl, t_vect pos)
{
	t_vect	normal;

	normal = sub_vect(pos, cyl->o);
	if (cyl->axe.y == 1)
		normal.y = 0;
	else if (cyl->axe.x == 1)
		normal.x = 0;
	else if (cyl->axe.z == 1)
		normal.z = 0;
	return (normal);
}

float			inter_cylindre(t_obj *object, t_ray *ray, t_inter *inter)
{
	t_cylindre	*cylindre;
	float		tmp;
	t_vect		pos;

	cylindre = (t_cylindre*)object->obj;
	tmp = calc_poly(cylindre, ray);
	if (tmp != -1)
	{
		pos = add_vect(ray->o, mult_float(ray->dir, tmp));
		tmp = magnitude(sub_vect(pos, ray->o));
		if (inter->dist == -1 || tmp < inter->dist)
		{
			inter->pos = pos;
			inter->normal = calc_normal(cylindre, pos);
			inter->dist = tmp;
			inter->obj = object;
		}
	}
	return (tmp);
}
