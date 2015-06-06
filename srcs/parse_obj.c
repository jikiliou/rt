/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 11:47:46 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/04 06:53:32 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	parse_sphere(char **res, t_scene *scene)
{
	t_obj	*sphere;
	t_vect	center;

	if (ft_ptrlen(res) < 11)
		ft_error("Bad argument for sphere", NULL);
	sphere = new_obj();
	center = vect(ft_atoi(res[2]), ft_atoi(res[3]), ft_atoi(res[4]));
	sphere->obj = (void*)new_sphere(center, ft_atoi(res[6]));
	sphere->type = SPHERE;
	sphere->color = init_color(ft_atoi(res[8]), ft_atoi(res[9]),
			ft_atoi(res[10]));
	if (ft_ptrlen(res) == 13)
		sphere->mat = search_material(scene->all_material, res[12]);
	else if (scene->default_mat != NULL)
		sphere->mat = scene->default_mat;
	else
		ft_error("No material By default", NULL);	
	put_obj(sphere, scene);
}

void	parse_cylindre(char **res, t_scene *scene)
{
	t_obj	*cyl;
	t_vect	axe;
	t_vect	o;

	if (ft_ptrlen(res) < 15)
		ft_error("Bad argument for cylindre", NULL);
	cyl = new_obj();
	o = vect(ft_atoi(res[2]), ft_atoi(res[3]), ft_atoi(res[4]));
	axe = vect(ft_atoi(res[6]), ft_atoi(res[7]), ft_atoi(res[8]));
	cyl->obj = (void*)new_cylindre(o, axe, ft_atoi(res[10]));
	cyl->type = CYLINDRE;
	cyl->color = init_color(ft_atoi(res[12]), ft_atoi(res[13]),
			ft_atoi(res[14]));
	if (ft_ptrlen(res) == 17)
		cyl->mat = search_material(scene->all_material, res[16]);
	else if (scene->default_mat != NULL)
		cyl->mat = scene->default_mat;
	else
		ft_error("No material By default", NULL);
	put_obj(cyl, scene);
}

void	parse_cone(char **res, t_scene *scene)
{
	t_obj	*cone;
	t_vect	o;
	t_vect	axe;

	if (ft_ptrlen(res) < 15)
		ft_error("Bad argument for cone", NULL);
	cone = new_obj();
	o = vect(ft_atoi(res[2]), ft_atoi(res[3]), ft_atoi(res[4]));
	axe = vect(ft_atoi(res[6]), ft_atoi(res[7]), ft_atoi(res[8]));
	cone->obj = (void*)new_cone(o, axe, ft_atoi(res[10]));
	cone->type = CONE;
	cone->color = init_color(ft_atoi(res[12]), ft_atoi(res[13]),
			ft_atoi(res[14]));
	if (ft_ptrlen(res) == 17)
		cone->mat = search_material(scene->all_material, res[16]);
	else if (scene->default_mat != NULL)
		cone->mat = scene->default_mat;
	else
		ft_error("No material By default", NULL);
	put_obj(cone, scene);
}

void	parse_plan(char **res, t_scene *scene)
{
	t_obj	*plan;
	t_vect	o;
	t_vect	axe;

	if (ft_ptrlen(res) < 13)
		ft_error("Bad argument for plan", NULL);
	plan = new_obj();
	o = vect(ft_atoi(res[2]), ft_atoi(res[3]), ft_atoi(res[4]));
	axe = vect(ft_atoi(res[6]), ft_atoi(res[7]), ft_atoi(res[8]));
	plan->obj = (void*)new_plan(o, axe);
	plan->type = PLAN;
	plan->color = init_color(ft_atoi(res[10]), ft_atoi(res[11]),
			ft_atoi(res[12]));
	if (ft_ptrlen(res) == 15)
		plan->mat = search_material(scene->all_material, res[14]);
	else if (scene->default_mat != NULL)
		plan->mat = scene->default_mat;
	else
		ft_error("No material By default", NULL);
	put_obj(plan, scene);
}

void	parse_light(char **res, t_scene *scene)
{
	t_light	*light;
	t_vect	pos;

	if (ft_ptrlen(res) < 11)
		ft_error("Bad argument for light", NULL);
	pos = vect(ft_atoi(res[2]), ft_atoi(res[3]), ft_atoi(res[4]));
	light = create_light(pos, ft_atoi(res[6]) / (float)10);
	light->coef_color.r = ft_atoi(res[8]) / 255.f * light->intensity;
	light->coef_color.g = ft_atoi(res[9]) / 255.f * light->intensity;
	light->coef_color.b = ft_atoi(res[10]) / 255.f * light->intensity;
	put_light(light, scene);
}
