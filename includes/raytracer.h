/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 17:12:08 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/06 23:20:54 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

# define WIN_X	640
# define WIN_Y	480

# define SPHERE 0
# define PLAN 1
# define CONE 2
# define CYLINDRE 3
# define NB_TYPE 4

# define RAD(x) ((x) * M_PI / 180)

# define MAX_REFLEC 2

# define MATERIAL_PATH "./file/all_material/"

/*
 * BASE
 */

typedef struct	s_vect
{
	float	x;
	float	y;
	float	z;
}				t_vect;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct	s_coef
{
	float r;
	float g;
	float b;
}				t_coef;

/*
** MINILIBX
*/

typedef struct	s_pict
{
	void	*mlx;
	void	*win;
	void	*pic;
	char	*data;
	int		bpp;
	int		sz;
	int		endian;
}				t_pict;

/*
** OBJECT
*/

typedef struct	s_sphere
{
	t_vect	c;
	float	r;
}				t_sphere;

typedef struct	s_plan
{
	t_vect	pos;
	t_vect	normal;
}				t_plan;

typedef struct	s_cone
{
	t_vect	o;
	t_vect	axe;
	int		alpha;
	float	cos_sin[2];
}				t_cone;

typedef struct	s_cylindre
{
	t_vect	o;
	t_vect	axe;
	int		r;
}				t_cylindre;

/*
 * SCENE
 */

typedef struct	s_plane
{
	float	w;
	float	h;
	float	dist;
	t_vect	up_left;
}				t_plane;

typedef struct	s_cam
{
	t_vect	o;
	t_vect	dir;
	t_vect	up_dir;
	t_vect	right_dir;
	t_plane *plane;
}				t_cam;

typedef struct	s_ray
{
	t_vect	o;
	t_vect	dir;
	int		dist;
}				t_ray;

typedef struct	s_light
{
	t_vect			pos;
	t_coef			coef_color;
	float			intensity;
	struct s_light	*next;
}				t_light;

typedef struct	s_material
{
	char 				*name;
	float				spec_coef;
	float				diff_coef;
	float				amb_coef;
	float				reflec;
	float				transparent;
	struct s_material	*next;
}				t_material;

typedef struct	s_obj
{
	void			*obj;
	t_material		*mat;
	int				type;
	t_color			color;
	struct s_obj	*next;
}				t_obj;

typedef struct	s_inter
{
	int		dist;
	t_obj	*obj;
	t_vect	normal;
	t_vect	reflect;
	t_vect	pos;
}				t_inter;

typedef float	(*t_ptrfunc)(t_obj*, t_ray*, t_inter*);

typedef struct	s_scene
{
	t_obj		*objs;
	t_material	*default_mat;
	t_material	*all_material;
	t_cam		*cam;
	t_pict		*pict;
	t_light		*light;
	t_ptrfunc	*ptr;
}				t_scene;

/*
** VECTOR
*/

void			fill_vect(t_vect *vec, float x, float y, float z);
t_vect			vect(float x, float y, float z);
t_vect			add_vect(t_vect v1, t_vect v2);
t_vect			sub_vect(t_vect o, t_vect dir);
t_vect			mult_vect(t_vect v1, t_vect v2);
t_vect			mult_float(t_vect v1, float mult);
float			dot_product(t_vect v1, t_vect v2);
t_vect			div_float(t_vect v1, float mult);
void			norm_vect(t_vect *vec);
float			magnitude(t_vect vec);

/*
** IMPORTANT
*/

t_pict			*fill_pict(void);
void			raytrace_moi_ca(t_scene *scene);
t_color			ray_go_to_the_world_and_dont_forget_to_draw(t_scene *scene, t_ray *ray, int level);
void			draw_pixel(t_color color, t_pict *pict);

/*
** COLOR
*/

t_color			ambiant_color(t_light *light, t_inter *inter);
t_color			add_color(t_color final, t_color other);
t_color			mult_color(t_color color, float nb);
t_color			init_color(int r, int g, int b);
t_color			calc_color(t_inter *inter, t_ray *light_ray, t_light *light,
									t_ray *ray);

t_color			reflection(t_scene *scene, t_inter *inter, t_color pixel_color, int level);

/*
** PARSING
*/

t_light			*create_light(t_vect pos, float i);
t_cone			*new_cone(t_vect pos, t_vect axe, int alpha);
t_cylindre		*new_cylindre(t_vect o, t_vect axe, int rayon);
t_plan			*new_plan(t_vect pos, t_vect normal);
t_sphere		*new_sphere(t_vect center, int rayon);

void			parse_light(char **res, t_scene *scene);
void			parse_cone(char **res, t_scene *scene);
void			parse_sphere(char **res, t_scene *scene);
void			parse_cylindre(char **res, t_scene *scene);
void			parse_plan(char **res, t_scene *scene);

void			parse_moi_ca(int fd, t_scene *scene);
void			put_light(t_light *light, t_scene *scene);
void			put_obj(t_obj *object, t_scene *scene);
t_obj			*new_obj();

/*
 * MATERIAL
 */
t_material		*search_material(t_material	*all, char *name);
t_material		*material_take(char **res, t_material *all);
t_material		*find_all_material(void);
void			make_my_cam(char **res, t_scene *scene);

/*
** INTERSECTION
*/

float			inter_sphere(t_obj *object, t_ray *ray, t_inter *inter);
float			inter_cylindre(t_obj *object, t_ray *ray, t_inter *inter);
float			inter_cone(t_obj *object, t_ray *ray, t_inter *inter);
float			inter_plan(t_obj *object, t_ray *ray, t_inter *inter);

#endif
