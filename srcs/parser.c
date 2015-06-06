/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 20:28:25 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/04 07:00:35 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_obj	*new_obj(void)
{
	t_obj	*new;

	if (!(new = (t_obj*)malloc(sizeof(t_obj))))
		ft_error("MALLOC ERROR IN NEW OBJ", NULL);
	new->obj = NULL;
	new->type = -1;
	new->color.r = 0;
	new->color.g = 0;
	new->color.b = 0;
	new->next = NULL;
	new->mat = NULL;
	return (new);
}

void	put_obj(t_obj *object, t_scene *scene)
{
	t_obj	*tmp;

	if (scene->objs == NULL)
		scene->objs = object;
	else
	{
		tmp = scene->objs;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = object;
	}
}

void	put_light(t_light *light, t_scene *scene)
{
	t_light	*tmp;

	if (scene->light == NULL)
		scene->light = light;
	else
	{
		tmp = scene->light;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = light;
	}
}

void	do_you_get_it(char **res, t_scene *scene)
{
	if (res[0] == NULL)
		return ;
	if (ft_strcmp(res[0], "sphere") == 0)
		parse_sphere(res, scene);
	else if (ft_strcmp(res[0], "cylindre") == 0)
		parse_cylindre(res, scene);
	else if (ft_strcmp(res[0], "cone") == 0)
		parse_cone(res, scene);
	else if (ft_strcmp(res[0], "plan") == 0)
		parse_plan(res, scene);
	else if (ft_strcmp(res[0], "light") == 0)
		parse_light(res, scene);
	else if (ft_strcmp(res[0], "cam") == 0)
		make_my_cam(res, scene);
	else if (ft_strcmp(res[0], "material") == 0)
		scene->default_mat = material_take(res, scene->all_material);	
	else
		ft_error("Bad argument", NULL);
}

void	parse_moi_ca(int fd, t_scene *scene)
{
	char	*line;
	char	**res;

	while (get_next_line(fd, &line) > 0)
	{
		replace_comment(line, '#');
		res = ft_strsplit(line, ' ');
		do_you_get_it(res, scene);
		free(line);
		free_chch(res);
	}
}
