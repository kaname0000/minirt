/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:43:06 by okaname           #+#    #+#             */
/*   Updated: 2025/05/01 19:44:45 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "color/color.h"
# include "make_object/object.h"
# include "mlx/mlx.h"
# include "vector/vec.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_ray
{
	t_vec		start;
	t_vec		dir;
}				t_ray;

typedef struct s_world
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endain;
	int			screen_width;
	int			screen_height;
	t_camera	*cameras;
	t_obj		*objects;
	t_color		ambient;
	t_light		*lights;
}				t_world;

t_vec			hit_intersection(t_vec sphere, t_vec camera, t_vec screen,
					double r);
bool			is_zerovec(t_vec vec);
// double			diffuse_reflection(t_vec light, t_vec intersection,
// 					t_vec sphere);
double			diffuse_reflection(t_light *light, t_insec insec);
// double			specular_reflection(t_vec camera, t_vec intersection,
// 					t_vec light, t_vec sphere);
double			specular_reflection(t_ray ray, t_insec insec, t_light *light);
void			print_vec(t_vec vec);
// double			ambient_light(t_vec intersection, double k, double i);
double			ambient_light(int flag, double k, double i);
void			raytracing(t_world *world);
void			my_mlx_pixel_put(t_world *world, int x, int y, int color);
t_insec			trace_nearest(t_ray ray, t_obj *obj);
t_vec			ray_dir(t_world *world, t_camera *camera, int i, int j);

#endif