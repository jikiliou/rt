/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 18:15:34 by jabadie           #+#    #+#             */
/*   Updated: 2015/05/03 16:53:33 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vect	mult_float(t_vect v1, float mult)
{
	t_vect	vec;

	fill_vect(&vec, v1.x * mult, v1.y * mult, v1.z * mult);
	return (vec);
}

float	dot_product(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vect	div_float(t_vect v1, float mult)
{
	t_vect vec;

	fill_vect(&vec, v1.x / mult, v1.y / mult, v1.z / mult);
	return (vec);
}

float	magnitude(t_vect vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

void	norm_vect(t_vect *vec)
{
	float	mag;

	mag = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	vec->x /= mag;
	vec->y /= mag;
	vec->z /= mag;
}
