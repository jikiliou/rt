/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 20:44:35 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/07 01:53:48 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <stdio.h>

t_ray	calc_ray(t_cam *cam, float x, float y)
{
	t_vect	vec;
	t_ray	ray;

	vec = mult_float(cam->right_dir, x);
	vec = add_vect(cam->plane->up_left, vec);
	vec = sub_vect(vec, mult_float(cam->up_dir, y));
	ray.o = cam->o;
	ray.dir = sub_vect(vec, cam->o);
	norm_vect(&ray.dir);
	ray.dist = 0;
	return (ray);
}

int		light_obstacle(t_scene *scene, t_ray *light_ray, t_inter *inter,
		t_obj *obj)
{
	t_obj	*object;
	float	tmp_dist;

	tmp_dist = inter->dist;
	object = scene->objs;
	while (object != NULL)
	{
		if (object != obj)
		{
			if (scene->ptr[object->type](object, light_ray, inter) != -1)
			{
				if (tmp_dist != inter->dist)
					return (1);
			}
		}
		object = object->next;
	}
	return (0);
}

t_color	light_calc(t_scene *scene, t_inter *inter, t_ray *ray, int level)
{
	t_ray	light_ray;
	t_light	*light;
	t_inter	inter_light;
	t_color	final;

	(void)ray;
	(void)level;
	final = init_color(0, 0, 0);
	light = scene->light;
	while (light != NULL)
	{
		light_ray.dir = sub_vect(inter->pos, light->pos);
		inter_light.dist = magnitude(light_ray.dir);
		norm_vect(&light_ray.dir);
		light_ray.o = light->pos;
		if (light_obstacle(scene, &light_ray, &inter_light, inter->obj) == 0)
			final = add_color(final, calc_color(inter, &light_ray, light, ray));
		final = add_color(final, ambiant_color(light, inter));
		light = light->next;
	}
	//	final = reflection(scene, inter, final, level);
	return (final);
}

t_color	ray_go_to_the_world_and_dont_forget_to_draw(t_scene *scene, t_ray *ray, int level)
{
	t_inter	inter;
	t_color	color;
	t_obj	*object;

	inter.dist = -1;
	object = scene->objs;
	while (object != NULL)
	{
		scene->ptr[object->type](object, ray, &inter);
		object = object->next;
	}
	if (inter.dist != -1)
		color = light_calc(scene, &inter, ray, level);
	else
		color = init_color(0, 0, 0);
	return (color);
}

void	raytrace_moi_ca(t_scene *scene)
{
	int		x;
	float	x_ind;
	int		y;
	float	y_ind;
	t_ray	ray;
	t_color	color;

	x_ind = scene->cam->plane->w / WIN_X;
	y_ind = scene->cam->plane->h / WIN_Y;
	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			ray = calc_ray(scene->cam, x * x_ind, y * y_ind);
			color = ray_go_to_the_world_and_dont_forget_to_draw(scene, &ray, 0);
			draw_pixel(color, scene->pict);
			x++;
		}
		if (y % 20 == 0)
			printf("En cours: %.2f%%\n", (float)y / WIN_Y * 100);
		y++;
	}
	ft_putendl("FINI !");
}
