/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 18:11:30 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/04 03:53:05 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_sphere	*new_sphere(t_vect center, int rayon)
{
	t_sphere	*new;

	if (!(new = (t_sphere*)malloc(sizeof(t_sphere))))
		ft_error("MALLOC OBJECT", NULL);
	new->c = center;
	new->r = rayon;
	return (new);
}

t_plan		*new_plan(t_vect pos, t_vect normal)
{
	t_plan		*new;

	if (!(new = (t_plan*)malloc(sizeof(t_plan))))
		ft_error("MALLOC OBJECT", NULL);
	new->pos = pos;
	new->normal = normal;
	norm_vect(&new->normal);
	return (new);
}

t_cylindre	*new_cylindre(t_vect o, t_vect axe, int rayon)
{
	t_cylindre	*new;

	if (!(new = (t_cylindre*)malloc(sizeof(t_cylindre))))
		ft_error("MALLOC OBJECT", NULL);
	new->o = o;
	new->axe = axe;
	new->r = rayon;
	norm_vect(&new->axe);
	return (new);
}

t_cone		*new_cone(t_vect pos, t_vect axe, int alpha)
{
	t_cone	*new;

	if (!(new = (t_cone*)malloc(sizeof(t_cone))))
		return (NULL);
	new->o = pos;
	new->axe = axe;
	new->alpha = alpha;
	new->cos_sin[0] = pow(cos(RAD(new->alpha)), 2);
	new->cos_sin[1] = pow(sin(RAD(new->alpha)), 2);
	norm_vect(&new->axe);
	return (new);
}

t_light		*create_light(t_vect pos, float i)
{
	t_light	*first;

	if (!(first = (t_light*)malloc(sizeof(t_light))))
		ft_error("MALLOC ERROR IN REATE LIGHT", NULL);
	first->pos = pos;
	first->intensity = i;
	first->next = NULL;
	return (first);
}
