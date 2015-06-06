/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 05:27:26 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/06 17:12:34 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "dirent.h"


void	instruction_material(t_material *mat, char *str)
{
	char	**res;
	int		len;

	res = ft_strsplit(str, ' ');
	if (res[0] != NULL)
	{
		if ((len = ft_ptrlen(res)) == 2)
		{
			if (ft_strcmp(res[0], "name") == 0)
				mat->name = ft_strdup(res[1]);
			else if (ft_strcmp(res[0], "reflection") == 0)
				mat->reflec = ft_atoi(res[1]) / 100.f;
			else
				ft_error("Wrong in mat: ", str);
		}
		else if (len == 3)
		{
			if (ft_strcmp(res[0], "diffuse") == 0)
				mat->diff_coef = ft_atoi(res[2]) / 255.f;
			else if (ft_strcmp(res[0], "specular") == 0)
				mat->spec_coef = ft_atoi(res[2]) / 255.f;
			else if (ft_strcmp(res[0], "ambiant") == 0)
				mat->amb_coef = ft_atoi(res[2]) / 255.f;
			else
				ft_error("Wrong in mat: ", str);
		}
	}
	free_chch(res);
}

t_material	*read_material(char *file_name)
{
	int		fd;
	char	*line;
	t_material	*mat;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_error("Hmmm bon ben voili voulou", NULL);
	free(file_name);
	if (!(mat = ft_memalloc(sizeof(t_material))))
		ft_error("MALLOC ERROR IN NEW MATERIAL", NULL);
	while (get_next_line(fd, &line) > 0)
	{
		replace_comment(line, '#');
		instruction_material(mat, line);
		free(line);
	}
	close(fd);
	return (mat);
}

t_material	*find_all_material(void)
{
	DIR				*mat_dir;
	struct dirent	*file;
	t_material		*mat;
	t_material		*first;

	mat = NULL;
	first = NULL;
	if (!(mat_dir = opendir(MATERIAL_PATH)))
		ft_error("Hmm Wrong path in the define...", NULL);
	while ((file = readdir(mat_dir)))
	{
		if (file->d_name[0] == '.')
			continue ;
		if (mat == NULL)
		{
			mat = read_material(ft_strjoin(MATERIAL_PATH, file->d_name));
			first = mat;
		}
		else
		{
			mat->next = read_material(ft_strjoin(MATERIAL_PATH, file->d_name));
			mat = mat->next;
		}
	}
	closedir(mat_dir);
	return (first);
}
