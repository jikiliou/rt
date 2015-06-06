/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 06:07:19 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/04 07:21:05 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_material	*search_material(t_material	*all, char *name)
{
	while (all)
	{
		if (ft_strcmp(all->name, name) == 0)
			return (all);
		all = all->next;
	}
	ft_error("Wrong name of material: ", name);
	return (NULL);
}

t_material	*material_take(char **res, t_material *all)
{
	if (ft_ptrlen(res) != 2)
		ft_error("WRONG WRITING FOR MATERIAL", NULL);
	return (search_material(all, res[1]));
}
