/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 01:48:34 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/07 01:40:08 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

float	inter_plan(t_obj *object, t_ray *ray, t_inter *inter)
{
	t_plan	*plan;
	float	t;
	float	dv;
	t_vect	pos;
	float	tmp;

	plan = (t_plan*)object->obj;
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
		inter->dist = tmp;
		inter->obj = object;
	}
	return (tmp);
}
