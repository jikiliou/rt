/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_my_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 18:02:15 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/04 01:57:01 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_plane	*fill_my_plane(t_cam cam)
{
	t_plane	*new;
	t_vect	ratio_dir;
	t_vect	ratio_up;
	t_vect	ratio_right;

	if (!(new = (t_plane*)malloc(sizeof(t_plane))))
		ft_error("MALLOC ERROR IM FILL MY PLANE", NULL);
	new->w = 0.5;
	new->h = 0.35;
	new->dist = 1;
	ratio_dir = mult_float(cam.dir, new->dist);
	ratio_up = mult_float(cam.up_dir, new->h / 2);
	ratio_right = mult_float(cam.right_dir, new->w / 2);
	ratio_dir = add_vect(ratio_dir, ratio_up);
	ratio_dir = add_vect(cam.o, ratio_dir);
	new->up_left = sub_vect(ratio_dir, ratio_right);
	return (new);
}

t_cam	*new_cam(t_vect look, t_vect cam)
{
	t_cam	*new;

	if (!(new = (t_cam*)malloc(sizeof(t_cam))))
		ft_error("MALLOC ERROR IN NEW_CAM", NULL);
	new->o = cam;
	fill_vect(&new->up_dir, 0, 1, 0);
	new->dir = sub_vect(look, new->o);
	norm_vect(&new->dir);
	new->right_dir = mult_vect(new->up_dir, new->dir);
	new->up_dir = mult_vect(new->dir, new->right_dir);
	norm_vect(&new->right_dir);
	norm_vect(&new->up_dir);
	new->plane = fill_my_plane(*new);
	return (new);
}

void	make_my_cam(char **res, t_scene *scene)
{
	t_vect	look_at;
	t_vect	cam;

	if (ft_ptrlen(res) < 9)
		ft_error("Bad argument for cam", NULL);
	cam = vect(ft_atoi(res[2]), ft_atoi(res[3]), ft_atoi(res[4]));
	look_at = vect(ft_atoi(res[6]), ft_atoi(res[7]), ft_atoi(res[8]));
	if (scene->cam == NULL)
		scene->cam = new_cam(look_at, cam);
	else
		ft_error("Only one cam", NULL);
}
