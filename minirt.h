/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/26 10:34:52 by okaname           #+#    #+#             */
/*   Updated: 2025/04/26 10:34:52 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "color/color.h"
# include "mlx/mlx.h"
# include "vector/vec.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

enum e_objtype
{
	SP,
	PL,
	C,
	TR,
	SQ,
	CY
};

typedef struct s_list
{
	t_vec position;
	t_color color;
	double diameter;
	t_vec normal;
	double height;
	enum e_objtype type;
	struct s_list *next;

} t_list;

typedef struct s_ray
{
	t_vec start;
	t_vec dir;
} t_ray;

typedef struct s_sectpt
{
	double distance;
	t_vec position;
	t_vec normal;
} t_sectpt;

typedef struct s_dlist
{
	double x;
	double y;
	double z;
	struct s_dlist *next;

} t_dlist;

typedef struct s_world
{
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endain;
	int screen_width;
	int screen_height;
	t_dlist *cameras;
	t_list *objects;
	t_color ambient;
	t_list *lights;
} t_world;

t_vec	hit_intersection_s(t_vec sphere, t_vec camera, t_vec screen, double r);
bool	is_zerovec(t_vec vec);
double	diffuse_reflection(t_vec light, t_vec intersection, t_vec sphere);
double	specular_reflection(t_vec camera, t_vec intersection, t_vec light,
		t_vec sphere);
void	print_vec(t_vec vec);
double	ambient_light(t_vec intersection, double k, double i);

#endif