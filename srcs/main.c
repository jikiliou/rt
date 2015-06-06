/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 20:44:25 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/04 07:08:53 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <stdio.h>

t_ptrfunc	*create_t_ptrfunc(void)
{
	t_ptrfunc	*ptr;

	if (!(ptr = (t_ptrfunc*)malloc(sizeof(t_ptrfunc) * NB_TYPE)))
		ft_error("MALLOC ERROR IN CREATE t_ptrfunc", NULL);
	ptr[SPHERE] = &inter_sphere;
	ptr[PLAN] = &inter_plan;
	ptr[CONE] = &inter_cone;
	ptr[CYLINDRE] = &inter_cylindre;
	return (ptr);
}

t_scene		*fill_scene(int fd)
{
	t_scene	*new;

	if (!(new = (t_scene*)malloc(sizeof(t_scene))))
		ft_error("MALLOC ERROR IN FILL SCENE", NULL);
	new->objs = NULL;
	new->light = NULL;
	new->cam = NULL;
	new->default_mat = NULL;
	if (!(new->all_material = find_all_material()))
		ft_error("No Material, No Work !!!", NULL);
	parse_moi_ca(fd, new);
	if (new->cam == NULL || new->objs == NULL || new->light == NULL)
		ft_error("You will see nothing", NULL);
	new->pict = fill_pict();
	new->ptr = create_t_ptrfunc();
	return (new);
}

int			draw(t_scene *scene)
{
	mlx_put_image_to_window(scene->pict->mlx, scene->pict->win,
			scene->pict->pic, 0, 0);
	return (0);
}

int			key_hook(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int			main(int ac, char **av)
{
	t_scene	*scene;
	int		fd;

	if (ac != 2)
		ft_error("You must put an input file, thanks", NULL);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error("No file with this name : ", av[1]);
	scene = fill_scene(fd);
	raytrace_moi_ca(scene);
	mlx_key_hook(scene->pict->win, key_hook, scene);
	mlx_expose_hook(scene->pict->win, draw, scene);
	mlx_loop(scene->pict->mlx);
	return (0);
}
