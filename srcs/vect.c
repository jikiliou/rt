/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 18:08:09 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/04 02:10:39 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	fill_vect(t_vect *vec, float x, float y, float z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_vect	vect(float x, float y, float z)
{
	t_vect	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vect	add_vect(t_vect v1, t_vect v2)
{
	t_vect vec;

	fill_vect(&vec, v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	return (vec);
}

t_vect	sub_vect(t_vect o, t_vect dir)
{
	t_vect	vec;

	fill_vect(&vec, (o.x - dir.x), (o.y - dir.y), (o.z - dir.z));
	return (vec);
}

t_vect	mult_vect(t_vect v1, t_vect v2)
{
	t_vect vec;

	fill_vect(&vec, v1.y * v2.z - v1.z * v2.y,
					v1.z * v2.x - v1.x * v2.z,
					v1.x * v2.y - v1.y * v2.x);
	return (vec);
}
